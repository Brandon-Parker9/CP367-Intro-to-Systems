#!/bin/bash

# constants
RETURN_OK=0
RETURN_BAD=1

# Check if the number of arguments provided is less than 1 or greater than 2
if [ "$#" -lt 1 ] || [ "$#" -gt 2 ]; then
    echo "Usage: $0 <directory> [extension]"
    exit $RETURN_BAD
fi

# grab the first argument
directory=$1

# Check if the directory exists
if [ ! -d "$directory" ]; then
    echo "Error: Directory '$directory' does not exist."
    exit $RETURN_BAD
fi

# Set the extension to the second argument or to "*" (all files) if not provided
if [ "$#" -eq 2 ]; then
    # grab second argument if provided
    extension=".$2"
else
    # if no second argument, do all extensions
    extension="*"
fi

# Count the number of regular files in the directory with the given extension
file_count=$(find "$directory" -type f -name "*$extension" | wc -l)

# output number of files found
echo "Number of regular files in directory '$directory': $file_count"

exit $RETURN_OK
