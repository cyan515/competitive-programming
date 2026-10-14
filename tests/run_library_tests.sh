#!/bin/sh
set -eu

CXX_BIN="${CXX:-g++}"
REPO_ROOT="$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)"
TEST_BIN="${TMPDIR:-/tmp}/competitive-programming-library-smoke-test"
TEST_JOBS="${TEST_JOBS:-4}"

find "$REPO_ROOT/my-library" -type f -name '*.cpp' -print0 \
  | xargs -0 -n 1 -P "$TEST_JOBS" "$CXX_BIN" -std=gnu++23 \
    -Wall -Wextra -Wshadow -I"$REPO_ROOT/ac-library" -fsyntax-only

"$CXX_BIN" -std=gnu++23 -O0 -Wall -Wextra -Wshadow \
  "$REPO_ROOT/tests/library_smoke_test.cpp" -o "$TEST_BIN"
"$TEST_BIN"
rm -f "$TEST_BIN"
