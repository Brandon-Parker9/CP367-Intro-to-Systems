#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX 30

int runCommand(char *command){
    // Create a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process executing\n");
        exit(EXIT_SUCCESS); 
        // Child-specific code here
    } else {
        // Parent process
        printf("Parent process waiting for child\n");
        wait(NULL); // Parent process waits for the child to terminate
        printf("Parent process is done waiting\n");
    }
    return 0;
}

int main( int argc, char *argv[] ) {

    // defining buffer
    char str_buf[MAX];
    char *token;
    char delimiters[] = " \n";

    while(1){

        printf("myshell>");
        // using fgets to take input from stdin
        fgets(str_buf, MAX, stdin);
        printf("\nstring is: %s\n", str_buf);

        token = strtok(str_buf, delimiters);

        // while( token != NULL ) {
        //     printf( "%s\n", token );
            
        //     token = strtok(NULL, delimiters);
        // }

        printf("Token: %s\n", token);

        if (strcmp(token, "echo") == 0)
        {
            printf("Running echo\n");
            runCommand(str_buf);
        } else if (strcmp(token, "uname") == 0)
        {
            printf("Running uname\n");
            runCommand(str_buf);
        }else if (strcmp(token, "touch") == 0)
        {   
            printf("Running touch\n");
            runCommand(str_buf);
        }else if (strcmp(token, "q") == 0)
        {   
            printf("Exiting due to user enter q\n");
            break;
        } else {
            printf("Invalid command, please try again.\n");
        }
        
    }

    return 0;

}

