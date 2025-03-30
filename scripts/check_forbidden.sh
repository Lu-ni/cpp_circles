#!/bin/bash

# Forbidden keywords and functions based on 42 C++ module rules
forbidden_patterns=("printf" "malloc" "calloc" "realloc" "free" "using namespace std" "friend")
has_error=0

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD='\033[1m'
NC='\033[0m' # No Color

for file in "$@"; do
  found=0
  for pattern in "${forbidden_patterns[@]}"; do
    if grep -q "$pattern" "$file"; then
      found=1
      break
    fi
  done

  if [ "$found" -eq 1 ]; then
    echo -e "${BOLD}${file}:${NC} ${RED}KO${NC} – Forbidden pattern(s) detected"
    # Print matched lines with red-highlighted forbidden words
    while IFS= read -r line; do
      line_number=$(echo "$line" | cut -d: -f1)
      code_line=$(echo "$line" | cut -d: -f2-)
      for pattern in "${forbidden_patterns[@]}"; do
        code_line=$(echo "$code_line" | sed "s/\b$pattern\b/${RED}${pattern}${NC}/g")
      done
      echo -e "  → ${line_number}: ${code_line}"
    done < <(grep -nE "$(IFS=\|; echo "${forbidden_patterns[*]}")" "$file")
    has_error=1
  else
    echo -e "${BOLD}${file}:${NC} ${GREEN}OK${NC}"
  fi
done

exit $has_error
