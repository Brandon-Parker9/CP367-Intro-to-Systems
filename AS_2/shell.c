#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 30

int runCommand(char *commands[]){
    // Create a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        // printf("Child process executing\n");

        execvp(commands[0], commands);

        exit(EXIT_SUCCESS); 
        // Child-specific code here
    } else {
        // Parent process
        // printf("Parent process waiting for child\n");
        wait(NULL); // Parent process waits for the child to terminate
        // printf("Parent process is done waiting\n");
    }
    return 0;
}

int main( int argc, char *argv[] ) {

    // defining buffer
    char str_buf[MAX];
    char *token = NULL;
    char delimiters[] = " \n";
    char **commands = NULL;
    int count;

    while(1){

        count = 0;

        printf("myshell> ");

        // using fgets to take input from stdin
        fgets(str_buf, MAX, stdin);
        // printf("\nstring is: %s\n", str_buf);

        token = strtok(str_buf, delimiters);

        if(token == NULL){
            continue;
        }

        while( token != NULL ) {
            // printf( "Token: %s\n", token );

            commands = realloc(commands, (count + 1) * sizeof(char*));
            commands[count] = malloc(strlen(token) + 1);
            strcpy(commands[count], token);
           
            count++;

            token = strtok(NULL, delimiters);
        }

        // printf("commands[0]: %s\n", commands[0]);

        // printf("strcmp(commands[0], q): %d\n", strcmp(commands[0], "q"));

        if (strcmp(commands[0], "echo") == 0)
        {
            runCommand(commands);

        } else if (strcmp(commands[0], "uname") == 0)
        {
            runCommand(commands);

        }else if (strcmp(commands[0], "touch") == 0)
        {   
            runCommand(commands);

        }else if (strcmp(commands[0], "q") == 0)
        {   
            break;

        } else {

            printf("Invalid command, please try again.\n");
        }

        // Print the words
        // printf("Commands:\n");
        for (int i = 0; i < count; i++) {
            // printf("Command: %s\n", commands[i]);
            free(commands[i]); // Free memory allocated for each word
        }

        // Free the array itself
        free(commands);

        commands = NULL;
        
    }

    return 0;

}

