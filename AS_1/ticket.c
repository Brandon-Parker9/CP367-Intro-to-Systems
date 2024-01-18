#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {

    char time[20];
    int age;
    int scanf_return_value;
    printf("Time: ");
    scanf("%s" , time);
    
    // validate if user is putting in one of the two options

    if (strcmp(time, "night") != 0 && strcmp(time, "day") != 0)
    {
        return 1;
    }
    
    // while (strcmp(time, "night") != 0 && strcmp(time, "day") != 0)
    // {
    //     // printf("night compare: %d day compare: %d \n", strcmp(time, "night"), strcmp(time, "day"));
    //     while (getchar() != '\n');

    //     // printf("Time input: %s", time);

    //     printf("Invalid input. Please enter the time(day or night): ");
    //     scanf("%s", &time);
    // }
    

    printf("Age: ");
    scanf_return_value = scanf("%d", &age);

    // validate if the user is inputting a positive number
    if (age < 0 || scanf_return_value != 1)
    {
        return 1;
    }
    
    
    // while (age < 0 || scanf_return_value != 1)
    // {
    //     if (scanf_return_value != 1)
    //     {
    //         while (getchar() != '\n');
    //     }

    //     printf("Invalid input. Please enter a positive integer: ");
    //     scanf_return_value = scanf("%d", &age);
    // }

    // printf("You entered the following number: %d", age);

    // cases based on what the user input
    if (strcmp(time, "night") == 0 && age >= 4 && age <= 16){
        
        printf("$12");       
    
    } else if (strcmp(time, "night") == 0 && age >= 17 && age <= 54)
    {
    
        printf("$15"); 
    
    } else if (strcmp(time, "night") == 0 && age >= 55)
    {
    
        printf("$13"); 
    
    }else if (strcmp(time, "day") == 0 && age >=4 )
    {
    
        printf("$8");
    
    }else if (age < 4)
    {
    
        printf("free");
    
    }

    return 1;
};
