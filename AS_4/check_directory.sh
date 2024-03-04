#!/bin/bash

# Check if the number of arguments provided is less than 1 or greater than 2
if [ "$#" -lt 1 ] || [ "$#" -gt 2 ]; then
    echo "Usage: $0 <directory> [extension]"
    exit 1
fi

directory=$1

# Check if the directory exists
if [ ! -d "$directory" ]; then
    echo "Error: Directory '$directory' does not exist."
    exit 1
fi

# Set the extension to the second argument or to "*" (all files) if not provided
if [ "$#" -eq 2 ]; then
    extension=".$2"
else
    extension="*"
fi

# Count the number of regular files in the directory with the given extension
file_count=$(find "$directory" -type f -name "*$extension" | wc -l)

echo "Number of regular files in directory '$directory':"
echo "$file_count"ls

