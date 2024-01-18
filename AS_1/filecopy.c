#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ){

    // chekc if user put in 2 arguments 
    if (argc != 3){

        printf("Insufficient parameters passed.");

    } else {

        // printf("argument 1: %s argument 2: %s", argv[1], argv[2]);

        // attempted to open file
        FILE *filePtrInput =  fopen(argv[1], "r");

        // if failed to open file
        if (filePtrInput == NULL)
        {
            return 0;
        }else{

            char chr;

            // open output file
            FILE *filePtrOutput =  fopen(argv[2], "w");

            // add contents from input file to output file one character at time
            do {
            chr = fgetc(filePtrInput);
            fputc(chr , filePtrOutput);
    
            } while (chr != EOF);

            fclose(filePtrInput);
            fclose(filePtrOutput);

            printf("The contents of file %s have been successfully copied into the %s file.", argv[1], argv[2]);
        }

    }
    return 1;
}