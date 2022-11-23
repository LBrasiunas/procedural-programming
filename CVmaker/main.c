#include <stdio.h>
#include <stdlib.h>

// Header files responsible for creating the .css and .html files
#include "create_css.h"
#include "create_website_css.h"
#include "create_website_html.h"
#include "create_about_us_html.h"

// Functions
void numberValidation(int *n);
void checkMenu();
void getImageFilename(char filename[]);
int getCount();
void getName(char name[]);

int main()
{
    printf("                                                 CV Webpage creation tool\n\n");
    printf("This program helps you to create a web page file (.html) of your created CV. "
           "The information required for a basic CV will be entered to this program. "
           "Also, you will be able to set specific parameters of the style of your CV.\n\n"
           "If you want to continue, enter 1. If you want to exit the program enter 0.\n");

    // Creating the necessary files
    createCSSFile();
    createWebsiteCSSFile();
    createAboutUsHTML();
    createWebsiteHTML();

    checkMenu();

    FILE *myFile;
    // Result .html file name
    char fileName[] = "CV.html";
    myFile = fopen(fileName, "w");
    // Writing some html code to file
    fprintf(myFile, "%s", "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<title>Resume</title>\t"
            "\n<link href=\"https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600\" rel=\"stylesheet\">\t"
            "\n<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/meyer-reset/2.0/reset.min.css\">\n\t"
            "<link rel=\"stylesheet\" href=\"style.css\">\n</head>\n");

    // Some variables
    char imageFilename[50];
    char fullName[50] = "";
    char curPositionTitle[100] = "";
    char shortDescription[500] = "";

    // Calling a function responsible for getting the image file name
    getImageFilename(imageFilename);
    // Writing more html code to file with image file name
    fprintf(myFile, "%s%s%s", "<body>\n<div class=\"container\">\n<section>\n<div>\t"
            "\n<div><img src=\"",imageFilename,"\" alt=\"avatar\" class=\"avatar\"></div>\n</div>");

    printf("\nThe file name was entered successfully.\nPlease enter your full name (up to 50chr.):\n");
    // Calling a function responsible for getting the full name of the user from screen
    getName(fullName);

    printf("\nName entered successfully.\nPlease enter your current position (student, job title or ect.):\n");
    scanf("%[^\n]%*c", curPositionTitle);

    printf("\nCurrent position entered successfully.\nPlease enter a short description (up to 500chr.) about yourself:\n");
    scanf("%[^\n]%*c", shortDescription);
    printf("\nShort description entered successfully.\nEnter your job count: ");
    // Writing more html code with the previously entered data
    fprintf(myFile, "%s%s%s%s%s%s%s", "<div>\n<div class=\"my-name\">",fullName,"</div>\n<div class=\"my-title\">",curPositionTitle,"</div>\n\t"
            "<p>",shortDescription,"</p>\n</div>\n</section>\n\n<section>\n<div class=\"section-title\">Experience</div>\n");

    // Using a function for getting the number entered on screen
    int jobCount = getCount();
    printf("\nSuccess.");
    // Some variables used for the job section
    int jobStartYear, jobEndYear;
    char company[100], title[100], description[1000];
    // Beginning a cycle responsible for entering the data required for the job section
    for(int i = 0; i < jobCount; ++i)
    {
        printf("\nEnter the company name: ");
        scanf("%[^\n]%*c", company);
        printf("Enter the job title: ");
        scanf("%[^\n]%*c", title);
        printf("Enter the start year: ");
        numberValidation(&jobStartYear);
        printf("Enter the end year: ");
        numberValidation(&jobEndYear);
        printf("Enter a short description about it:\n");
        scanf("%[^\n]%*c", description);

        // Writing gathered information about a job after one cycle iteration with html code to result file
        fprintf(myFile, "%s%s%s%s%s%d%s%d%s%s%s", "\n\t"
                "<div>\n<div class=\"job\">\n<div class=\"job-title-container\">\n<div>\n<div class=\"job-company\">",company,"</div>\n\t"
                "<div class=\"job-title\">",title,"</div>\n</div>\n<div>\n",jobStartYear," - ",jobEndYear,"\n</div>\n</div> <!-- end job-title container -->\t"
                "<p>",description,"</p>\n</div> <!-- end job -->\n");
    }

    printf("\nJob experience entered successfully.\nNow enter the amount of universities or degrees finished: ");
    // Using a function for getting the number entered on screen
    int educationCount = getCount();
    printf("\nSuccess.");

    // Some variables used for the education section
    int eduStartYear, eduEndYear;
    char schoolName[100], degree[100];
    fprintf(myFile, "%s", "</div>\n</section>\n\n<section>\n<div class=\"section-title\">Education</div>\n<div>\n");
    // Beginning a cycle responsible for entering the data required for the education section
    for(int i = 0; i < educationCount; ++i)
    {
        printf("\nEnter the school or university name: ");
        scanf("%[^\n]%*c", schoolName);
        printf("Enter the degree: ");
        scanf("%[^\n]%*c", degree);
        printf("Enter the start year: ");
        numberValidation(&eduStartYear);
        printf("Enter the finish year: ");
        numberValidation(&eduEndYear);

        // Writing gathered information about education after one cycle iteration with html code to result file
        fprintf(myFile, "%s%s%s%s%s%d%s%d%s", "<div class=\"job\">\n\t"
                "<div class=\"job-title-container\">\n<div>\n<div class=\"job-company\">",schoolName,"</div>\t"
                "<div class=\"job-title\">",degree,"</div>\n</div>\n<div>\n",eduStartYear," - ",eduEndYear,"\n</div>\n\t"
                "</div> <!-- end job-title container -->\n</div> <!-- end job -->\n</div>\n</section>\n");
    }

    printf("\nAll of the required information entered successfully! The .html file of your CV is being created right now...\n");
    // Writing the end of the html code to result file
    fprintf(myFile, "%s", " </div>\n</body>\n</html>\n");
    fclose(myFile);
    printf("The webpage created successfully!\nExiting the program...\n");

    return 0;
}

// A function responsible for validating a number and returning it to the main function using a pointer
void numberValidation(int *n)
{
    // Running a cycle until the user enters a valid number
    while(1)
    {
        *n = -1;
        char c = 'c';
        if(scanf("%9d%c", n, &c) == 2 && (c == '\n' || c == ' '))
            break;
        else
        {
            printf("Wrong input!\n");
            // A cycle responsible for discarding useless entered information
            while(!isspace(getchar()))
                ;
        }
    }
}

// A function responsible for checking whether the user wants to continue using the program or wants to exit it
void checkMenu()
{
    int menuNumber;
    // Running a cycle until the user enters 1 or 0
    while(1)
    {
        // Calling the number validation function
        numberValidation(&menuNumber);
        if(menuNumber == 1)
        {
            printf("Continuing the program...\n");
            break;
        }
        else if(!menuNumber)
        {
            printf("Exiting the program...\n");
            exit(0);
        }
        printf("Wrong input entered. Try again.\n");
    }
}

// A function responsible for getting the image file name and validating if it exists
void getImageFilename(char filename[])
{
    FILE *fp;
    printf("\nPlease enter the filename of the image you want to include (the file extension is necessary!):\n");
    // Running a cycle until the user enters a file that exists in the project's local directory
    while(1)
    {
        scanf ("%[^\n]%*c", filename);
        fp = fopen(filename, "r");
        if(fp == NULL)
            printf("The file does not exist! Try again.\n");
        else
        {
            fclose(fp);
            break;
        }
    }
}

// A function responsible for getting a number from the screen a validating it
int getCount()
{
    int count;
    // Running a cycle until the user enters a valid number that complies with the bottom if statement in this cycle
    while(1)
    {
        numberValidation(&count);
        if(count < 1)
            printf("\nWrong input! You should enter at least 1.\n");
        if(count > 3)
            printf("\nInput too large. The input should not be larger than 3.\n");
        if(count > 0 && count < 4)
            break;
    }
    // Returning the entered and validated number
    return count;
}

// A function responsible for getting the full name of the user from the screen
void getName(char name[])
{
    if(name[0] == '\n' || name[0] == '\0')
        scanf("%[^\n]%*c", name);
    else
        return;
}
