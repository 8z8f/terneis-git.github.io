#!/bin/sh
# nyx installer bootstrap. Fetches the `install` binary, marks it
# executable, runs it. The binary itself takes care of downloading
# external, first-run system setup, PATH wiring, and the launch prompt.
#
# Users paste one line:
#
#   curl -fsSL https://epries.xyz/install.sh | bash
#
# or, to keep an interactive stdin so the "launch external? [Y/n]"
# prompt actually shows up:
#
#   bash <(curl -fsSL https://epries.xyz/install.sh)
#
set -eu

BIN_URL="${NYX_INSTALL_URL:-https://epries.xyz/latest/install}"

# Pretty output only when connected to a real terminal.
if [ -t 1 ]; then
    B="$(printf '\033[1m')"
    P="$(printf '\033[38;5;213m')"   # pink, matches install binary's own accent
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

# Basic ELF sanity — first four bytes should be 7f 45 4c 46 ("\x7fELF").
head -c 4 "$tmp" | od -An -tx1 | tr -d ' \n' | grep -qi '^7f454c46' \
    || die "downloaded file isn't a Linux binary. bad URL?"

chmod +x "$tmp"
say "running installer"
printf '\n'

# Forward args + preserve stdin as a TTY when we have one, so the
# installer's interactive Y/N launch prompt still works.
"$tmp" "$@"
