// This program is intended to display the amount of numbers that begin with an odd number.
// Lukas Brasiūnas, 1 kursas, 2 grupė, 2021-10-13

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This program is intended to display the amount of numbers that begin with an odd number. "
           "Please enter whole numbers. If you enter a 0, the program will exit.\n");
    int number; // skaičiaus kintamasis
    char character; // simbolio kintamasis
    int oddNumberCount = 0; // kintamasis skirtas nelyginiais skaičiais prasidedantiems numeriams saugoti
    printf("Enter whole numbers:\n");
    while(number != 0) // ciklas veikiantis iki kol žmogus įves 0
    {
        if(scanf("%d%c", &number, &character) == 2 && (character == '\n' || character == ' ')) // validacijos dalis
        {
            if(number == 0) // sąlygos sakinys, kuris tikrina ar nuskaitytas skaičius yra 0
            {
                printf("0 entered. Exiting the program...\n");
                break;
            }
            printf("Entry successful.\n");
            while(1) // ciklas, skirtas surasti pačiam pirmam įvesto skaičiaus numeriui
            {
                if(number / 10 == 0) // sąlyga, tikrinanti ar tai pats pirmas skaičius
                {
                    if(number % 2 != 0) // sąlyga, tikrinanti ar tas skaičius nelyginis
                    {
                        oddNumberCount++;
                    }
                    break;
                }
                else // jeigu skaičius ne pats pirmas, dalina iš 10, taip pašalindamas paskutinį skaičių
                {
                    number /= 10;
                }
            }
        }
        else // validacijos dalis, metanti, kad įvestis neteisinga
        {
            printf("Incorrect input detected! Enter a whole number again:\n");
            while(!isspace(getchar()))
                ;
        }
    }
    printf("There were %d odd numbers entered.\n", oddNumberCount); // išveda kiek surado nelyginiais skaičiais prasidedančių įvesčių
    return 0;
}
