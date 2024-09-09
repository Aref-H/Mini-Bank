/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "startMenu.h"

// Declaring startMenu function
void startMenu()
{
    // Creating a money sign
    goToxy(66, 1);
    printf("$$\n");

    goToxy(59, 2);
    printf("    $$$$$$$$    \n");

    goToxy(59, 3);
    printf("  $$$  $$  $$$  \n");

    goToxy(59, 4);
    printf("$$$    $$    $$$\n");

    goToxy(59, 5);
    printf("$$$    $$    \n");

    goToxy(59, 6);
    printf("  $$$  $$    \n");

    goToxy(59, 7);
    printf("    $$$$$    \n");

    goToxy(59, 8);
    printf("       $$$$$  \n");

    goToxy(59, 9);
    printf("       $$  $$$  \n");

    goToxy(59, 10);
    printf("       $$    $$$  \n");

    goToxy(59, 11);
    printf("$$$    $$    $$$\n");

    goToxy(59, 12);
    printf("  $$$  $$  $$$  \n");

    goToxy(59, 13);
    printf("    $$$$$$$$    \n");

    goToxy(66, 14);
    printf("$$\n");


    goToxy(51, 16);

    // Creating a Main menu for the user
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");

    goToxy(49, 17);
    printf("**********************************");

    goToxy(55, 18);
    printf("DEVELOPER-Aref Heydari");

    goToxy(51, 21);
    printf("1.... CREATE A BANK ACCOUNT");

    goToxy(51, 23);
    printf("2.... ALREADY A USER? LOG IN");
    goToxy(51, 25);
    printf("3.... EXIT\n");

    int i;
    for (i = 0; i < 5; i++) { printf("\n"); }
    printf("\n\n\nENTER YOUR CHOICE...");
}

// Second menu to show after login
void uAccountMenu(char userName1[55])
{
    int i;
    FILE* fptr;
    struct usersData u1;

    errno_t err;
    errno = 0;
    char buffer[50];

    err = fopen_s(&fptr, "userData.txt", "rb");

    if (err != 0 || fptr == NULL)
    {
        strerror_s(buffer, 50, errno);
        system("cls");
        goToxy(55, 5);
        printf("Error : %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Menu to show user info
    while (fread(&u1, sizeof(u1), 1, fptr))
    {
        if (strcmp(userName1, u1.userName) == 0)
        {
            system("cls");
            goToxy(55, 2);
            printf("        ");
            printf("WELCOME %s %s", u1.uFName, u1.uLName);

            goToxy(8, 3);
            for (i = 0; i < 120; i++)
            {
                printf(".");
            }

            goToxy(90, 7);
            printf("**YOUR ACCOUNT INFO**");
            goToxy(86, 8);
            printf(".............................");

            goToxy(90, 10);
            printf("NAME :           %s", u1.uFName);

            goToxy(90, 12);
            printf("LAST NAME :      %s", u1.uLName);

            goToxy(90, 14);
            printf("NATIONAL CODE :  %s", u1.uNationalCode);

            goToxy(90, 16);
            printf("BRITH DATE :     %d/%d/%d", u1.year, u1.month, u1.date);

            goToxy(90, 18);
            printf("FATHER's NAME :  %s", u1.uFathName);

            goToxy(90, 20);
            printf("MOTHER's NAME :  %s", u1.uMothName);

            goToxy(90, 22);
            printf("PHONE NUMBER :   %s", u1.uPhonNum);

            goToxy(90, 24);
            printf("ADDRESS :        %s", u1.uAddress);

            goToxy(90, 26);
            printf("ACCOUNT TYPE :   %s", u1.typeAccount);
        }
    }

    fclose(fptr);

    // Making home menu
    goToxy(30, 7);
    printf("**HOME**");
    goToxy(20, 8);
    printf(".............................");

    goToxy(20, 10);
    printf("1.... CHECK BALANCE");

    goToxy(20, 12);
    printf("2.... TRANSFER MONEY");

    goToxy(20, 14);
    printf("3.... LOG OUT");

    goToxy(20, 16);
    printf("4.... EXIT");

    goToxy(0, 35);
    printf("ENTER YOUR CHOICE...");

    homeChoice();
}
