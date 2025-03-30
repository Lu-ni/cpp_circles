#!/bin/bash

# Path to your compiled C++ program
EXECUTABLE="./megaphone"

# Define test cases: each test has input args and expected output
# Format: args:::expected_output (NO leading :: in expected_output)
tests=(
  "\"shhhhh... I think the students are asleep...\":::SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
  "Damnit \" ! \" \"Sorry students, I thought this thing was off.\":::DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
  ":::* LOUD AND UNBEARABLE FEEDBACK NOISE *"
  "\"hello\":::HELLO"
  "\"HeLLo\" \"wORld\":::HELLO WORLD"
  "\"123 abc\":::123 ABC"
  "\"...\":::..."
  "\"  spaced  \":::SPACED"
  "\"!@#\$%^&*()_+\":::!@#\$%^&*()_+"
  "\"New\" \"Line\":::NEW LINE"
)

pass_count=0
fail_count=0

echo "Running megaphone tests..."
echo "---------------------------"

for test in "${tests[@]}"; do
  input_args="${test%%:::*}"
  expected="${test#*:::}"

  # Run the program and capture output
  output=$(eval "$EXECUTABLE $input_args")

  if [ "$output" == "$expected" ]; then
    echo "✅ Test passed: ./megaphone $input_args"
    ((pass_count++))
  else
    echo "❌ Test failed: ./megaphone $input_args"
    echo "   Expected: $expected"
    echo "   Got     : $output"
    ((fail_count++))
  fi
done

echo "---------------------------"
echo "✅ Passed: $pass_count"
echo "❌ Failed: $fail_count"
