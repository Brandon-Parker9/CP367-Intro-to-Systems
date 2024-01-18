#include <stdio.h>

// print array function for testing
// void print_array(int* arr, int size){

//     for(int i = 0 ; i < size ; i++){
//         printf("%d: %d\n", i, arr[i]);
//     }
// }

int main( int argc, char *argv[] ) {

    int number;
    int scanf_return_value;

    // asks user for number
    printf("Please enter a value for the Pascal triangle\n");
    scanf_return_value = scanf("%d", &number);

    // validate the users input
    if (number < 1 || number > 14 || scanf_return_value != 1)
    {
        printf("Invalid input. Please enter a positive Integer less than 15.\n");
        return 0;
    }
    

    // while (number < 1 || number > 14 || scanf_return_value != 1)
    // {
    //     if (scanf_return_value != 1)
    //     {
    //         // clear buffer if input is incorrect
    //         while (getchar() != '\n');
    //     }

    //     printf("Invalid input. Please enter a positive integer less than 15: ");
    //     scanf_return_value = scanf("%d", &number);
    // }

    // printf("You entered the following number: %d\n", number);
    
    int number_of_elemets = ((double)number/2)*(1+number);

    int arr[number_of_elemets];

    // printf("Number of elements in Pascal trianlge: %d\n", number_of_elemets);

    int curr_pos = 0;
    
    for (int i = 0; i < number; i++){
        
        if(i == 0){ // the "top" the triangle

            arr[curr_pos] = 1;

            printf("%d    ", arr[curr_pos]);

            curr_pos++;

        } else if (i == 1){ // second row of the triangle

            arr[curr_pos] = 1;

            printf("\n%d    ", arr[curr_pos]); 

            curr_pos++;
            arr[curr_pos] = 1;

            printf("%d    ", arr[curr_pos]);

            curr_pos++;  

        } else {

            // put in the two outside 1's
            arr[curr_pos] = 1;
            arr[curr_pos + i] = 1;

            printf("\n%d    ", arr[curr_pos]);

            for (int j = 1; j < i; j++){ // loop hrough and calculate the values in between the outside 1's

                arr[curr_pos + j] = arr[curr_pos + j - i - 1] + arr[curr_pos + j - i];

                printf("%d    ", arr[curr_pos + j]);

                // printf("I: %d J: %d VALUE: %d\n", i, j, arr[curr_pos + j]);

            }

            curr_pos += i + 1;

            printf("%d    ", arr[curr_pos - 1]);
        }

        // printf("Curr_pos: %d\n", curr_pos);

    }

    printf("\n");

    // print_array(arr, number_of_elemets);

    return 0;
};
