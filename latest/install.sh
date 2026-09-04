set -eu

BIN_URL="${NYX_INSTALL_URL:-https://epries.xyz/latest/install}"

if [ -t 1 ]; then
    B="$(printf '\033[1m')"
    P="$(printf '\033[38;5;213m')"   
    D="$(printf '\033[2m')"
    R="$(printf '\033[0m')"
else
    B= ; P= ; D= ; R=
fi

say()  { printf '  %s%s%s\n' "$D" "$*" "$R"; }
die()  { printf '\n  %serror:%s %s\n\n' "$P" "$R" "$*" >&2; exit 1; }

command -v curl >/dev/null 2>&1 || die "curl is required"

tmp="$(mktemp -t nyx-install.XXXXXX)"
trap 'rm -f "$tmp"' EXIT INT HUP TERM

printf '\n  %s%sNYX%s %sinstaller%s\n\n' "$B" "$P" "$R" "$D" "$R"
say "fetching $BIN_URL"
curl -fsSL -o "$tmp" "$BIN_URL" \
    || die "download failed. check your connection or the URL."

head -c 4 "$tmp" | od -An -tx1 | tr -d ' \n' | grep -qi '^7f454c46' \
    || die "downloaded file isn't a Linux binary. bad URL?"

chmod +x "$tmp"
say "running installer"
printf '\n'

"$tmp" "$@"
