set -euo pipefail

readonly URL="https://epries.xyz/latest/NYX.tar.gz"
readonly DEST_DIR="${HOME}/NYX"
readonly TMPDIR="$(mktemp -d -t nyx-install-XXXXXX)"
trap 'rm -rf "$TMPDIR"' EXIT

# palette
if [[ -t 1 ]]; then
    A_BOLD=$'\033[1m'; A_DIM=$'\033[2m'; A_RST=$'\033[0m'
    C_ACCENT=$'\033[38;5;213m'
    C_LABEL=$'\033[38;5;245m'
    C_MUTED=$'\033[38;5;240m'
    C_OK=$'\033[38;5;120m'
    C_WARN=$'\033[38;5;220m'
    C_ERR=$'\033[38;5;203m'
else
    A_BOLD= A_DIM= A_RST= C_ACCENT= C_LABEL= C_MUTED= C_OK= C_WARN= C_ERR=
fi

banner() {
    printf '\n'                                                              >&2
    printf '  %s%sNYX%s %s%sexternal%s\n' \
        "$A_BOLD" "$C_ACCENT" "$A_RST" "$A_DIM" "$C_MUTED" "$A_RST"          >&2
    printf '  %s────────────────%s\n\n' "$C_MUTED" "$A_RST"                  >&2
}
row()    { printf '  %s%-10s%s  %s\n' "$C_LABEL" "$1" "$A_RST" "$2"           >&2; }
note()   { printf '  %s%s%s\n' "$C_MUTED" "$*" "$A_RST"                       >&2; }
warn()   { printf '  %s%s%s\n' "$C_WARN" "$*" "$A_RST"                        >&2; }
die()    { printf '\n  %s%s%s\n\n' "$C_ERR" "$*" "$A_RST" >&2; exit 1; }

# privilege
if [[ $EUID -eq 0 ]]; then
    SUDO=""
elif command -v sudo >/dev/null 2>&1; then
    SUDO="sudo"
elif command -v doas >/dev/null 2>&1; then
    SUDO="doas"
else
    SUDO=""
fi

# distro detection
detect_distro_tokens() {
    if [[ -r /etc/os-release ]]; then
        # shellcheck disable=SC1091
        . /etc/os-release
        printf '%s %s\n' "${ID:-unknown}" "${ID_LIKE:-}"
    fi
}
distro_name() {
    if [[ -r /etc/os-release ]]; then
        # shellcheck disable=SC1091
        . /etc/os-release
        printf '%s\n' "${PRETTY_NAME:-${NAME:-Linux}}"
    else
        printf 'Linux\n'
    fi
}

resolve_packages() {
    local tokens="$1" id like
    read -r id like <<<"$tokens"
    for tok in $id $like; do
        case "$tok" in
            arch|manjaro|endeavouros|garuda|arcolinux|artix)
                echo "pacman|glfw-x11 libx11 libglvnd mesa"; return ;;
            debian|ubuntu|linuxmint|pop|elementary|zorin|kali|parrot|raspbian|mx|deepin|neon)
                echo "apt|libglfw3 libx11-6 libgl1 libglx0"; return ;;
            fedora|rhel|centos|rocky|almalinux|ol|nobara)
                if command -v dnf >/dev/null 2>&1
                then echo "dnf|glfw libX11 libglvnd mesa-libGL"
                else echo "yum|glfw libX11 libglvnd mesa-libGL"
                fi; return ;;
            opensuse*|suse|sles)
                echo "zypper|libglfw3 libX11-6 Mesa-libGL1"; return ;;
            void)
                echo "xbps|glfw libX11 libglvnd mesa"; return ;;
            alpine|postmarketos)
                echo "apk|glfw libx11 mesa-gl"; return ;;
            gentoo|funtoo)
                echo "emerge|media-libs/glfw x11-libs/libX11 media-libs/libglvnd"; return ;;
            nixos)
                echo "nix|glfw xorg.libX11 libGL"; return ;;
            solus)
                echo "eopkg|glfw libx11 libglvnd"; return ;;
        esac
    done
    return 1
}

# package check
pkg_installed() {
    local mgr="$1" pkg="$2"
    case "$mgr" in
        pacman)  pacman -Qi "$pkg"    >/dev/null 2>&1 ;;
        apt)     dpkg -s "$pkg"       >/dev/null 2>&1 ;;
        dnf|yum) rpm -q "$pkg"        >/dev/null 2>&1 ;;
        zypper)  rpm -q "$pkg"        >/dev/null 2>&1 ;;
        xbps)    xbps-query "$pkg"    >/dev/null 2>&1 ;;
        apk)     apk info -e "$pkg"   >/dev/null 2>&1 ;;
        emerge)  { command -v qlist >/dev/null 2>&1 && qlist -I "$pkg" >/dev/null 2>&1; } \
                 || equery list "$pkg" >/dev/null 2>&1 ;;
        eopkg)   eopkg info "$pkg" 2>/dev/null | grep -q '^Installed' ;;
        nix)     nix-env -q 2>/dev/null | grep -q "^${pkg}-" ;;
        *)       return 1 ;;
    esac
}

install_pkgs() {
    local mgr="$1"; shift
    case "$mgr" in
        pacman)  $SUDO pacman -S --needed --noconfirm "$@" ;;
        apt)     $SUDO apt-get update -qq
                 DEBIAN_FRONTEND=noninteractive $SUDO apt-get install -y --no-install-recommends "$@" ;;
        dnf)     $SUDO dnf install -y "$@" ;;
        yum)     $SUDO yum install -y "$@" ;;
        zypper)  $SUDO zypper --non-interactive install "$@" ;;
        xbps)    $SUDO xbps-install -Sy "$@" ;;
        apk)     $SUDO apk add --no-cache "$@" ;;
        emerge)  $SUDO emerge --ask=n --noreplace "$@" ;;
        eopkg)   $SUDO eopkg install -y "$@" ;;
        nix)     nix-env -iA $(printf 'nixpkgs.%s ' "$@") ;;
    esac
}

# fetch + extract
fetch_archive() {
    local out="$TMPDIR/NYX.tar.gz"
    if command -v curl >/dev/null 2>&1; then
        curl -fsSL --retry 3 --retry-delay 2 -o "$out" "$URL"
    elif command -v wget >/dev/null 2>&1; then
        wget -q --tries=3 -O "$out" "$URL"
    else
        die "need curl or wget to download."
    fi
    [[ -s "$out" ]] || die "download produced empty file."
    printf '%s' "$out"
}

extract_archive() {
    local archive="$1"
    [[ -e "$DEST_DIR" ]] && rm -rf "$DEST_DIR"
    mkdir -p "$DEST_DIR"
    mkdir -p "$DEST_DIR/configs"

    local top_count nested_count
    top_count=$(tar -tzf "$archive" | awk -F/ '{print $1}' | sort -u | wc -l)
    nested_count=$(tar -tzf "$archive" | grep -c '/' || true)
    if [[ "$top_count" -eq 1 && "$nested_count" -gt 0 ]]; then
        tar -xzf "$archive" -C "$DEST_DIR" --strip-components=1
    else
        tar -xzf "$archive" -C "$DEST_DIR"
    fi

    find "$DEST_DIR" -mindepth 1 -print -quit | grep -q . \
        || die "extraction produced no files — archive layout unexpected."
}

install_desktop_file() {
    local bin="$1" icon="$2"
    [[ -z "$bin" ]] && return 1

    local apps_dir="${XDG_DATA_HOME:-$HOME/.local/share}/applications"
    mkdir -p "$apps_dir"
    local dest="$apps_dir/nyx-external.desktop"

    {
        printf '[Desktop Entry]\n'
        printf 'Type=Application\n'
        printf 'Name=NYX External\n'
        printf 'GenericName=Roblox Overlay\n'
        printf 'Comment=External overlay for Roblox on the Sober Linux runtime\n'
        printf 'Exec=sudo %s\n' "$bin"
        [[ -n "$icon" && -f "$icon" ]] && printf 'Icon=%s\n' "$icon"
        printf 'Terminal=true\n'
        printf 'Categories=Game;Utility;\n'
        printf 'StartupNotify=false\n'
    } > "$dest"

    chmod 644 "$dest"
    if command -v update-desktop-database >/dev/null 2>&1; then
        update-desktop-database "$apps_dir" >/dev/null 2>&1 || true
    fi

    printf '%s' "$dest"
}

is_elf() {
    local magic
    magic=$(dd if="$1" bs=1 count=4 status=none 2>/dev/null | od -An -tx1 | tr -d ' \n')
    [[ "$magic" == "7f454c46" ]]
}

mark_executable() {
    local main=""
    for name in external NYX nyx nyx-external; do
        local hit
        hit=$(find "$DEST_DIR" -type f -name "$name" -print -quit 2>/dev/null || true)
        if [[ -n "$hit" ]]; then chmod +x "$hit"; main="$hit"; break; fi
    done
    if [[ -z "$main" ]]; then
        while IFS= read -r -d '' f; do
            if is_elf "$f"; then chmod +x "$f"; main="$f"; break; fi
        done < <(find "$DEST_DIR" -type f -print0)
    fi
    printf '%s' "$main"
}

# format helpers
human_size() {
    local bytes
    bytes=$(stat -c%s "$1" 2>/dev/null || wc -c <"$1")
    awk -v b="$bytes" 'BEGIN {
        split("B KB MB GB TB", u); i=1
        while (b >= 1024 && i < 5) { b /= 1024; i++ }
        if (i == 1) printf "%d %s", b, u[i]
        else        printf "%.1f %s", b, u[i]
    }'
}

# main
banner

spec=""
if ! spec=$(resolve_packages "$(detect_distro_tokens)"); then
    warn "unrecognised distro — install glfw, libX11 and OpenGL manually,"
    warn "then re-run with  SKIP_DEPS=1 ./installer.sh"
    [[ "${SKIP_DEPS:-0}" == "1" ]] || die "aborting."
fi

manager="${spec%%|*}"
pkgs="${spec#*|}"
sys_line="$(distro_name)  ${A_DIM}${C_MUTED}·${A_RST} ${manager}"

missing=(); present=()
if [[ -n "$spec" && "${SKIP_DEPS:-0}" != "1" ]]; then
    for p in $pkgs; do
        if pkg_installed "$manager" "$p"; then present+=("$p"); else missing+=("$p"); fi
    done

    if [[ ${#missing[@]} -gt 0 ]]; then
        note "installing: ${missing[*]}"
        [[ -z "$SUDO" && $EUID -ne 0 ]] && die "sudo/doas required to install packages."
        install_pkgs "$manager" "${missing[@]}"
        pkg_line="${C_OK}installed${A_RST}   ${A_DIM}${C_MUTED}${missing[*]}${A_RST}"
    else
        pkg_line="${C_OK}present${A_RST}     ${A_DIM}${C_MUTED}${pkgs}${A_RST}"
    fi
else
    pkg_line="${A_DIM}${C_MUTED}skipped${A_RST}"
fi

archive="$(fetch_archive)"
size="$(human_size "$archive")"
extract_archive "$archive"
main_bin="$(mark_executable)"

icon_file=""
for cand in "${DEST_DIR}/NYX.png" "${DEST_DIR}"/*/NYX.png; do
    [[ -f "$cand" ]] && { icon_file="$cand"; break; }
done

desktop_file=""
if [[ -n "$main_bin" ]]; then
    desktop_file="$(install_desktop_file "$main_bin" "$icon_file" || true)"
fi

row "system"   "$sys_line"
row "packages" "$pkg_line"
row "archive"  "${size}      ${A_DIM}${C_MUTED}NYX.tar.gz${A_RST}"
row "installed" "${main_bin:-$DEST_DIR}"
if [[ -n "$desktop_file" ]]; then
    row "shortcut" "${desktop_file}"
fi

printf '\n' >&2
if [[ -n "$main_bin" ]]; then
    printf '  %srun%s  %s%ssudo %s%s\n\n' \
        "$C_LABEL" "$A_RST" "$A_BOLD" "$C_ACCENT" "$main_bin" "$A_RST"        >&2
    note "(root is required to read /proc/PID/mem of the Roblox process)"
else
    warn "binary not detected — inspect ${DEST_DIR} manually."
fi
printf '\n' >&2
