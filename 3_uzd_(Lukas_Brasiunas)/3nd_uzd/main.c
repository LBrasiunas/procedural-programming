// Lukas Brasiunas, 1 kursas, 2 grupe, 1 pogrupis
// This program manipulates the given input file by removing all of the whitespace between
// two words if the first word's last letter is identical to the second word's first letter.

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Special variable for defining the maximum length of characters in one text line of the input file
#define MAX_LINE_SIZE 256

// Global variables
FILE *fp;
FILE *fp1;

// Functions
void validateCommandLineInput(int arg_count, char *arguments[], char filename[], int *file_size);
void dataReading(char *arr, int *file_size);
void dataManipulating(char *input_arr, char *output_arr);

int main(int argc, char *argv[])
{
    printf("This program manipulates the given input file by removing all of the whitespace between "
           "two words if the first word's last letter is identical to the second word's first letter.\n");

    // Some variables
    char fileName[] = "";
    int fileSize = 0;


    // Zone for testing purposes
    /*argc = 1;
    argv[1] = "failas.txt";
    argv[2] = "rez.txt";*/


    // Calling the command line validation function if an input file was specified
    if(argc >= 2)
    {
        printf("Trying to open the specified input file.\n");
        validateCommandLineInput(argc, argv, argv[1], &fileSize);
    }
    // Calling the command line validation function if an input file was not specified
    // and returning the input filename to int main
    if(argc == 1)
    {
        validateCommandLineInput(argc, argv, fileName, &fileSize);
        argv[1] = fileName;
    }

    // Removing the previous output file with the same name
    if(argc == 3)
    {
        remove(argv[2]);
        printf("\nOutput file was specified. Open %s to see the results.\n", argv[2]);
    }
    else
        printf("\nNo output file specified. Displaying the results on screen:\n");


    // Opening the input file
    fp = fopen(argv[1], "r");
    // Beginning a cycle till the end of the input file (EOF)
    while(getc(fp) != EOF)
    {
        // Defining a couple of dynamic arrays
        char *input = calloc((MAX_LINE_SIZE + 1), sizeof(char));
        char *output = calloc((MAX_LINE_SIZE + 1), sizeof(char));

        // Returning to the correct position of the input file after an iteration of the cycle
        fseek(fp, -1, SEEK_CUR);

        // Calling a function responsible for reading the input file and storing one line information
        // to the dynamic array (input)
        dataReading(input, &fileSize);

        // Calling a function responsible for manipulating the given information in the correct way
        dataManipulating(input, output);


        // Identifying if there was an output filename specified
        if(argc == 3)
        {
            // Storing the manipulated data in an output file
            fp1 = fopen(argv[2], "a");
            if(fp1 == NULL)
            {
                printf("Could not create or write to output file. Exiting the program...\n");
                exit(0);
            }
            fprintf(fp1, "%s\n", output);
            fclose(fp1);
        }
        // Displaying the results if an output filename was not specified
        else
        {
            printf("%s\n", output);
        }
        free(input);
        free(output);
    }
    // Closing the input file
    fclose(fp);
    return 0;
}

//A function responsible for validating the command line arguments
void validateCommandLineInput(int arg_count, char *arguments[], char filename[], int *file_size)
{
    // If an input filename was not given, telling the user to enter it now
    if(arg_count == 1)
    {
        printf("No arguments entered. Please enter an input file name including it's extension.\n");
        // A cycle responsible for getting a correct input filename from the user
        while(1)
        {
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if(fp == NULL)
                printf("File not found! Enter a new file name.\n");
            else
            {
                printf("File name that exists entered successfully.\n");
                break;
            }
        }
    }

    // Seeing if the given input filename in the command line exists
    else if(arg_count > 1)
    {
        fp = fopen(filename, "r");
        if(fp == NULL)
        {
            printf("Entered input file not found. Exiting the program...\n");
            fclose(fp);
            exit(1);
        }
        printf("Input file opened successfully!\n");
    }

    // Getting the input file size
    fseek(fp, 0L, SEEK_END);
    *file_size = ftell(fp);
    // Recognizing if the input file has no data in it and exiting the program
    if(file_size == 0)
    {
        printf("No data in input file! Exiting the program...\n");
        fclose(fp);
        exit(1);
    }
    fclose(fp);
}

// A function responsible for reading the data from the input file and storing it in a dynamic array
void dataReading(char *arr, int *file_size)
{
    // Some variables
    char character;
    int index = 0;

    // Running a cycle till the end of the file or the end of the line
    while(*file_size != 0 && character != '\n')
    {
        --*file_size;
        // Storing information until the specified line length
        if(index < MAX_LINE_SIZE)
        {
            character = getc(fp);
            arr[index] = character;
            ++index;
        }
        // If the line consists more data than the max length specified, skips this data
        else
            getc(fp);
    }
    --*file_size;
}

// A function responsible for manipulating the given data in a correct way by removing unwanted whitespace between words
void dataManipulating(char *input_arr, char *output_arr)
{
    // Some variables
    int inputArrIndex = 0, outputArrIndex = 0, whitespaceCount = 0;

    // A cycle till the end of the given input line
    while(input_arr[inputArrIndex] != '\0')
    {
        // Recognizing and counting consecutive whitespace in the input array
        if(isspace(input_arr[inputArrIndex]))
        {
            ++whitespaceCount;
            ++inputArrIndex;
        }
        // Continuing if the current character from the input array is not a whitespace
        else
        {
            // Putting a character from the input array to the output array if there was no whitespace identified
            if(!whitespaceCount)
            {
                output_arr[outputArrIndex] = input_arr[inputArrIndex];
                ++outputArrIndex;
                ++inputArrIndex;
            }
            // Recognizing if there was whitespace identified
            else if(whitespaceCount)
            {
                // Seeing if the last character of the first word is identical to the first character of the second word
                if(input_arr[inputArrIndex] == input_arr[inputArrIndex - whitespaceCount - 1])
                {
                    output_arr[outputArrIndex] = input_arr[inputArrIndex];
                    ++outputArrIndex;
                    ++inputArrIndex;
                }
                // If the previous statement is incorrect - adding all of the whitespace identified to the output array
                else
                {
                    for(int i = 0; i < whitespaceCount; ++i)
                    {
                        output_arr[outputArrIndex] = ' ';
                        ++outputArrIndex;
                    }
                }
                // Resetting the whitespace counter variable
                whitespaceCount = 0;
            }
        }
    }
}
