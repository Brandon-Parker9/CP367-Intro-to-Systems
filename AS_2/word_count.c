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

                printf("\nContents of %s:\n\n", fileName);

                char chr;
                char prevChr;

                // Loop to read characters from the file
                do {

                // Read character from the file
                chr = fgetc(filePtrInput);

                // Print the character
                printf("%c", chr);

                if (chr == ' ')
                {   
                    // Increment word count if a space is encountered
                    words++;

                }else if (chr == '\n' || chr == EOF)
                {
                    
                    if (prevChr != '\n')
                    {
                        // Increment line counts if a newline or end-of-file is encountered
                        lines++;
                        words++;
                    }
                }
                
                // Store the current character for comparison in the next iteration
                prevChr = chr;

                } while (chr != EOF); // Continue reading until end-of-file is reached
                
                // Calculate the average number of words per line
                average = (float) words / lines;

                // Display the counts and average
                printf("\nNumber of lines of file: %d\nNumber of words of file: %d\nAverage number of words per line of file: %.2f\n\n",  lines, words, average);
            }

        } else if (input == 'q') {

            // If the user wants to quit the program
            printf("\nGood bye\n");
            break;
        } else {

             // If the user enters an invalid input
            printf("Invalid input. Please enter 'f' or 'q'.\n");
        }
    }

    // Return 0 to indicate successful program execution
    return 0;

}
