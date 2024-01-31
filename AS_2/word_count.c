#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {

    char input; // Variable to store user input for menu selection
    int words = 0, lines = 0; // Variables to count words and lines
    float average = 0.0; // Variable to store the average number of words per line
    char fileName[50]; // Array to store the file name entered by the user

    printf("This program counts the number of lines and words of a file\n");

    // Main loop for the program
    while (1) {
        printf("Enter f for entering file name, q to quit: ");
        scanf(" %c", &input);

        if (input == 'f') {
            
            // If the user wants to enter a file name
            printf("Enter file name: ");
            scanf("%s", fileName);

            // Attempt to open the file
            FILE *filePtrInput =  fopen(fileName, "r");

            // Check if the file opening was successful
            if (filePtrInput == NULL)
            {
                printf("\n%s cannot be opened\n\n", fileName);
            }else{

                printf("Content of %s:\n\n", fileName);

                char chr = ' ';
                char prevChr;

                // Read initial character from the file
                chr = fgetc(filePtrInput);

                // Loop to read characters from the file
                while (chr != EOF) {
                    // Print the character
                    printf("%c", chr);

                    // Check for space to increment word count
                    if (chr == ' ') {
                        words++;
                    // Check for space, newline, or punctuation marks to increment word count
                    // if (chr == ' ' || chr == '.' || chr == ',' || chr == ';' || chr == ':' || chr == '!' || chr == '?') {
                    //     // Check if the previous character was not a word delimiter
                    //     if (prevChr != ' ' && prevChr != '.' && prevChr != ',' && prevChr != ';' && prevChr != ':' && prevChr != '!' && prevChr != '?') {
                    //         words++;
                    //     }
                    } else if (chr == '\n') {
                        // Increment line count when a newline is encountered
                        lines++;

                        // Check if the previous character was not a newline
                        // This indicates the end of a word
                        if (prevChr != '\n') {
                            words++;
                        }
                    }

                    // Store the current character for comparison in the next iteration
                    prevChr = chr;

                    // Read character from the file
                    chr = fgetc(filePtrInput);
                }

                // Increment line count for the last line if it's not empty
                if (prevChr != '\n') {
                    lines++;
                }

                // Close the file after reading
                fclose(filePtrInput);

                // Calculate the average number of words per line
                average = (float) words / lines;

                // Display the counts and average
                printf("\nNumber of lines of %s: %d\nNumber of words of %s: %d\nAverage number of words per line of %s: %.2f\n", fileName, lines, fileName, words, fileName, average);
            }

        } else if (input == 'q') {

            // If the user wants to quit the program
            printf("Good bye\n");
            break;
        } else {

             // If the user enters an invalid input
            printf("Invalid input. Please enter 'f' or 'q'.\n");
        }
    }

    // Return 0 to indicate successful program execution
    return 0;

}
