/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "userChoice.h"

// Declaring a function to get user choice "Creat account, Sign in, exit"
void choice()
{
	char uChoice;

	uChoice = getch();

	if (uChoice == '1')
	{
		system("cls");
		goToxy(64, 5);
		printf("!NOTICE!\n");
		goToxy(46, 7);
		printf("User name     : !No more than 20 charecter!\n");
		goToxy(46, 8);
		printf("user password : !No more than 20 charecter!\n");
		goToxy(58, 9);
		printf("You may forget them!");
		account();
	}
	else if (uChoice == '2')
	{
		accountLogin();
	}
	else if (uChoice == '3')
	{
		int i;
		system("cls");
		goToxy(59, 18);
		printf("*** Good bye ***");
		for (i = 0; i < 12; i++) { printf("\n"); }
		delay(3.0);
		exit(0);
	}
	else
	{
		system("cls");
		goToxy(50, 18);
		printf("Notice! : pleas choose betwin \"1, 2, 3\"");
		delay(3.0);
		system("cls");
		startMenu();
		choice();
	}
}

char uuserName[50];

// Function to shoose user choice in home menu of user
void homeChoice()
{
	char uChoice;

	uChoice = getch();

	if (uChoice == '1')
	{
		system("cls");
		checkBalance(uuserName);
		uAccountMenu(uuserName);
		homeChoice();
	}
	else if (uChoice == '2')
	{
		system("cls");
		transferMoney();
		uAccountMenu(uuserName);
		homeChoice();
	}
	else if (uChoice == '3')
	{
		system("cls");
		startMenu();
		choice();
	}
	else if (uChoice == '4')
	{
		int i;
		system("cls");
		goToxy(59, 18);
		printf("*** Good bye ***");
		for (i = 0; i < 12; i++) { printf("\n"); }
		delay(3.0);
		exit(0);
	}
	else
	{
		
		system("cls");
		goToxy(50, 18);
		printf("Notice! : pleas choose betwin \"1, 2, 3, 4\"");
		delay(3.0);
		system("cls");
		uAccountMenu(uuserName);
		homeChoice();
		
	}
}

// Function to pass userName
void uAccountMenuNew(char uuserNameNew[50])
{
	strcpy_s(uuserName, sizeof(uuserName), uuserNameNew);
}