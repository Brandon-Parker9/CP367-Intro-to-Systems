#include <stdio.h>
#include <string.h>

#define MAX 30

int main( int argc, char *argv[] ) {

    // defining buffer
    char str_buf[MAX];
    char *token;

    while(1){

        // using fgets to take input from stdin
        fgets(str_buf, MAX, stdin);
        printf("string is: %s\n", str_buf);

        token = strtok(str_buf, ' ');
    }

    return 0;

}