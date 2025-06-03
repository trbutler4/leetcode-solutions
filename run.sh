#!/bin/bash

# LeetCode Solution Runner Script
# Usage: ./run.sh <problem_number> <language>
# Languages: python, go, rust, c

set -e

# Function to display usage
usage() {
    echo "Usage: $0 <problem_number> <language>"
    echo "Languages: python, go, rust, c"
    echo "Example: $0 88 python"
    exit 1
}

# Check arguments
if [ $# -ne 2 ]; then
    usage
fi

PROBLEM_NUM=$1
LANGUAGE=$2

# Validate language
case $LANGUAGE in
    python|go|rust|c)
        ;;
    *)
        echo "Error: Invalid language '$LANGUAGE'"
        usage
        ;;
esac

# Get script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROBLEMS_DIR="$SCRIPT_DIR/problems"

# Find problem directory
PROBLEM_DIR=""
for dir in "$PROBLEMS_DIR"/${PROBLEM_NUM}_*; do
    if [ -d "$dir" ]; then
        PROBLEM_DIR="$dir"
        break
    fi
done

if [ -z "$PROBLEM_DIR" ]; then
    echo "Error: Problem $PROBLEM_NUM not found"
    exit 1
fi

# Build solution directory path
SOLUTION_DIR="$PROBLEM_DIR/solution-$LANGUAGE"

if [ ! -d "$SOLUTION_DIR" ]; then
    echo "Error: $LANGUAGE solution not found for problem $PROBLEM_NUM"
    exit 1
fi

echo "Running problem $PROBLEM_NUM in $LANGUAGE..."
echo "Directory: $SOLUTION_DIR"
echo "$(printf '%0.s-' {1..50})"

cd "$SOLUTION_DIR"

# Run based on language
case $LANGUAGE in
    python)
        if [ ! -f "main.py" ]; then
            echo "Error: main.py not found in $SOLUTION_DIR"
            exit 1
        fi
        python3 main.py
        ;;
    go)
        if [ ! -f "main.go" ]; then
            echo "Error: main.go not found in $SOLUTION_DIR"
            exit 1
        fi
        if [ -f "main" ] && [ -x "main" ]; then
            ./main
        else
            go run main.go
        fi
        ;;
    rust)
        if [ ! -f "Cargo.toml" ]; then
            echo "Error: Cargo.toml not found in $SOLUTION_DIR"
            exit 1
        fi
        cargo run
        ;;
    c)
        if [ ! -f "main.c" ]; then
            echo "Error: main.c not found in $SOLUTION_DIR"
            exit 1
        fi
        if [ -f "main" ] && [ -x "main" ]; then
            ./main
        else
            gcc -o main main.c
            ./main
        fi
        ;;
esac