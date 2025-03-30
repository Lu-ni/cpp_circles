#!/bin/bash

forbidden_funcs=("printf" "malloc" "calloc" "realloc" "free")
has_error=0

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
NC='\033[0m' # No Color

for file in "$@"; do
  found=0
  for func in "${forbidden_funcs[@]}"; do
    if grep -q "$func" "$file"; then
      found=1
      break
    fi
  done

  if [ "$found" -eq 1 ]; then
    echo -e "${BOLD}${file}:${NC} ${RED}KO${NC} – Forbidden function(s) detected"
    grep -nE "$(IFS=\|; echo "${forbidden_funcs[*]}")" "$file" | sed 's/^/  → /'
    has_error=1
  else
    echo -e "${BOLD}${file}:${NC} ${GREEN}OK${NC}"
  fi
done

exit $has_error
