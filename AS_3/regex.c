#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    char inputFilename[100];

    // Get the name of the email text input file from the user
    printf("Enter the name of the input file: ");
    scanf("%99s", inputFilename);

    // Check if the input file exists
    if (access(inputFilename, F_OK) == -1) {
        fprintf(stderr, "Error opening input file\n");
        // printf("Error opening input file");
        return 1; // Return an error code to indicate failure
    }

    char outputFilename[100];

    // Get the name of the valid email text output file from the user
    printf("Enter the name of the output file for valid emails: ");
    scanf("%99s", outputFilename);

    // Define the shell command to filter valid emails using grep
    char command[300];
    sprintf(command, "grep -E '[a-z0-9_.+\\-]*[a-z0-9]+@[a-z0-9][a-z0-9_.\\-]*\\.[a-z]{2,}' %s > %s", inputFilename, outputFilename);

    // Execute the shell command using system() function
    int status = system(command);

    // Check if the command executed successfully
    if (status == 0) {
        printf("Valid emails extracted and saved to %s", outputFilename);
    } else {
        printf("Error occurred while filtering valid emails.\n");
    }

    return 0;
}