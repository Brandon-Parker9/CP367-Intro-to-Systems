#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {

    char input;
    int words = 0, lines = 0;
    float average = 0.0;
    char fileName[50];

    printf("This program counts the number of lines and words of a file\n");

    while (1) {
        printf("Enter f for entering file name, q to quit: ");
        scanf(" %c", &input);

        if (input == 'f') {
            
            printf("Enter file name: ");
            scanf(" %s", fileName);

            // attempted to open file
            FILE *filePtrInput =  fopen(argv[1], "r");

            // if failed to open file
            if (filePtrInput == NULL)
            {
                printf("\n%s cannot be opened\n\n", fileName);
            }else{

                // char chr;

                // // open output file
                // FILE *filePtrOutput =  fopen(argv[2], "w");

                // // add contents from input file to output file one character at time
                // do {
                // chr = fgetc(filePtrInput);
                // fputc(chr , filePtrOutput);

                // } while (chr != EOF);

                // fclose(filePtrInput);
                // fclose(filePtrOutput);

                printf("Number of lines of file: %d\nNumber of words of file: %d\nAverage number of words per line of file: %f\n", words, lines, average);
            }

        } else if (input == 'q') {
            // Exit the loop if 'q' is entered
            printf("\nGood bye\n");
            break;
        } else {
            // Handle invalid input
            printf("Invalid input. Please enter 'f' or 'q'.\n");
        }
    }

}
