// Lukas Brasiūnas, PS, 2 grupė, 1 pogrupis

// This program asks you to enter a positive whole number N and then N number of whole numbers.
// It outputs the closest two numbers to the average of all numbers entered, one lower, one higher.

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Array capacity
#define CAPACITY 1000
// Max value of an integer
#define INT_MAX 2147483647

// Defining functions
void wrongInputFlushing();
float calculateAverage(int sum, int n);

int main()
{
    // Variables
    int n, numberArray[CAPACITY], sumOfNumbers = 0, lowerNumberIndex = -1, higherNumberIndex = -1, arrayIndex = 0;
    float numberAverage, numberDifference, lowerNumberDifference = INT_MAX, higherNumberDifference = INT_MAX;
    char c;
    printf("This program asks you to enter a positive whole number N and then N number of whole numbers.\n"
            "It outputs the closest two numbers to the average of all numbers entered, one higher and one lower.\n\n");
    printf("Enter the amount of numbers you want to enter (not higher than %d): ", CAPACITY);

    // A loop specifically for data entering and it's validation
    while(1)
    {
        // If statement for validating the first number (N) entered
        if(scanf("%d%c", &n, &c) == 2 && (c == '\n' || c == ' ') && n > 0 && n <= CAPACITY)
        {
            printf("Now enter %d whole numbers:\n", n);

            // Temporary variable for the next number entered
            int temporaryNumber;

            // A loop for N amount of numbers to be entered
            while(arrayIndex < n)
            {
                // If statement for validating a new number entered (one of N numbers)
                if(scanf("%9d%c", &temporaryNumber, &c) == 2 && (c == '\n' || c == ' '))
                {
                    printf("Input successful.\n");
                    sumOfNumbers += temporaryNumber;
                    // Putting the entered number to an array
                    numberArray[arrayIndex] = temporaryNumber;
                    // Increasing array index variable
                    ++arrayIndex;
                }
                // Else statement for the number entered that is not valid
                else
                {
                    // Calling the function responsible for discarding useless information
                    wrongInputFlushing();
                }
            } // The end of the second loop

            printf("All numbers entered successfully!\n\n");
            // Stopping the first loop responsible for data gathering and validation
            break;
        } // The end of the first if statement
        // Else statement for the number N entered that is not valid
        else
        {
            // If and else if statements for recognizing if N number entered exceeded array limits
            if(n >= CAPACITY && (c == '\n' || c == ' '))
            {
                printf("Array capacity exceeded. Try again.\n");
            }
            else if(n < 1 && (c == '\n' || c == ' '))
            {
                printf("Amount entered not sufficient or wrong. Try again.\n");
            }
            // Else statement for calling the function responsible for discarding useless information
            else
            {
                wrongInputFlushing();
            }
        } // The end of the first else statement
    } // The end of the first loop

    // Calling the calculateAverage function
    numberAverage = calculateAverage(sumOfNumbers, n);
    // Printing useful information
    printf("Numbers entered: %d\nSum of numbers entered: %d\nAverage of numbers entered: %.3f\n",
            n, sumOfNumbers, numberAverage
            );



    // Starting a loop for finding the closest numbers to the average
    for(int i = 0; i < n; ++i)
    {
        // Calculating the difference between the number entered and the average
        numberDifference = numberArray[i] - numberAverage;
        // If statement for finding if a number is higher than the average and
        // if its difference is lower than the previous one
        if(numberDifference > 0 && numberDifference < higherNumberDifference)
        {
            higherNumberIndex = i;
            higherNumberDifference = numberDifference;
        }
        // Else if statement for finding if a number is lower than the average and
        // if its difference is lower than the previous one
        else if(numberDifference < 0 && numberDifference * -1 < lowerNumberDifference)
        {
            lowerNumberIndex = i;
            lowerNumberDifference = numberDifference * -1;
        }
    } // The end of the FOR loop

    // If statement responsible for recognizing if all of the N numbers entered are identical to each other
    if(higherNumberIndex == -1 || lowerNumberIndex == -1)
    {
        printf("All numbers entered are identical! No close numbers found. Exiting the program...\n");
        return 0;
    }

    // Printing out the main information
    printf("Higher number closest to the average is: %d\nLower number closest to the average is: %d\n",
           numberArray[higherNumberIndex], numberArray[lowerNumberIndex]);

    return 0;
}

// A function responsible for discarding useless information
void wrongInputFlushing()
{
    printf("Wrong input detected. Try again.\n");
    while(!isspace(getchar()))
        ;
}

// A function for calculating the average of all numbers entered
float calculateAverage(int sum, int n)
{
    return sum / 1.0 / n;
}
