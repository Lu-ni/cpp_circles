#!/bin/bash

ROOT_DIR="${1:-.}"

find "$ROOT_DIR" \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) | while read -r file; do
  echo "Adding header to $file"
  nvim --headless "$file" -c "Stdheader" -c "wq"
done
