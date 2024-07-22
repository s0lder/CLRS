#!/bin/bash

# Check if at least the directory argument is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <directory> [source_file]"
    exit 1
fi

# Extract arguments
DIR="$1"
SOURCE_FILE="${2:-main.cpp}"  # Use main.cpp as default if no source file is provided

# Change to the specified directory
cd "$DIR" || { echo "Directory $DIR not found"; exit 1; }

# Check if the specified source file exists
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: File $SOURCE_FILE not found in $DIR"
    exit 1
fi

# Compile the source file
g++ -o main "$SOURCE_FILE"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./main
else
    echo "Compilation failed."
    exit 1
fi
