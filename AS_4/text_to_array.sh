#!/bin/bash

# constants
RETURN_OK=0
RETURN_BAD=1

# Get the filename from input
filename=$1

# Check if the file exists
if [ ! -e "$filename" ]; then
  echo "Error: File '$filename' not found."
  exit $RETURN_BAD
fi

# Initialize variables
# word_array=()
word=""

echo "Array elements:"

# Read the file character by character
while IFS= read -r -n1 char; do

        # If it's an alphanumeric character, add it to the current word
        if [[ "$char" =~ [[:alnum:]] ]]; then
            word+="$char"

            # If it's a non-alphanumeric character and the current word is not empty:
            elif [ -n "$word" ]; then

                # Add the completed word to the array
                # word_array+=("$word")
                
                # print word 
                echo "$word"
                word=""
        fi
done < "$filename"

# If there's a leftover word, print it out
if [ -n "$word" ]; then
    echo "$word"
fi

# Print the array
# echo "Array elements:"
# for word in "${word_array[@]}"; do
#     echo "$word"
# done

exit $RETURN_OK