#!/usr/bin/env bash
set -euo pipefail

COMPILER="${CROSS_CC:-x86_64-w64-mingw32-gcc}"
echo "Using compiler: ${COMPILER}"

if ! command -v "${COMPILER}" >/dev/null 2>&1; then
    echo "Compiler ${COMPILER} not found. Install MinGW-w64 and ensure it is on PATH." >&2
    exit 1
fi

"${COMPILER}" -Wall -Wextra -municode qac_gui_sample.c -o qac_gui_sample.exe -lgdi32 -luser32
echo "Created qac_gui_sample.exe"
