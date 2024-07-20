# ~/projects/CLRS/compile_and_run.sh
#!/bin/bash

# Check if a directory argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Change to the specified directory
cd "$1" || exit

# Check if main.cpp exists in the directory
if [ ! -f main.cpp ]; then
    echo "Error: main.cpp not found in $1"
    exit 1
fi

# Compile the source file
g++ -o main main.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./main
else
    echo "Compilation failed."
    exit 1
fi
