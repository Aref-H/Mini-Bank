/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "makeAccount.h"

// A function to create account of users
void account()
{
	FILE* fptr;
	struct usersData u1;
	struct usersPassword p1;

	errno_t err;
	errno = 0;
	char buffer[50];

	// Opening file to write data of users
	err = fopen_s(&fptr, "userdata.txt", "ab");

	if (err != 0 || fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	// Take inputs
	delay(5.0);
	system("cls");
	goToxy(55, 5);
	printf("***CREATE ACCOUNT***");

	goToxy(55, 7);
	printf("Enter your First name : ");  // Take first name
	scanf_s("%19s", u1.uFName, (unsigned)_countof(u1.uFName));
	
	goToxy(55, 9);
	printf("Enter your Last name : ");  // Take last name
	scanf_s("%19s", u1.uLName, (unsigned)_countof(u1.uLName));

	goToxy(55, 11);
	printf("Enter your National Code : ");  // Take national code
	scanf_s("%14s", u1.uNationalCode, (unsigned)_countof(u1.uNationalCode));

	goToxy(55, 13);
	printf("Enter your date of birth...");  // Take brith date
	goToxy(55, 15);
	printf("Date \"In form 00\" : ");
	scanf_s("%2d", &u1.date);
	goToxy(55, 17);
	printf("Month \"In form 00\" : ");
	scanf_s("%2d", &u1.month);
	goToxy(55, 19);
	printf("Year  \"In form 0000\" : ");
	scanf_s("%4d", &u1.year);

	goToxy(55, 21);
	printf("Enter your Father name : ");  //Take father name
	scanf_s("%19s", u1.uFathName, (unsigned)_countof(u1.uFathName));

	goToxy(55, 23);
	printf("Enter your Mother name : ");  // Take mother name
	scanf_s("%19s", u1.uMothName, (unsigned)_countof(u1.uMothName));

	goToxy(55, 25);
	printf("Enter your Address : ");  // Take address
	scanf_s("%49s", u1.uAddress, (unsigned)_countof(u1.uAddress));

	goToxy(55, 27);
	printf("Enter your Phone number : ");  // Take phone number
	scanf_s("%14s", u1.uPhonNum, (unsigned)_countof(u1.uPhonNum));


	system("cls");  // Take Acount type
	goToxy(55, 5);
	printf("Enter your Account type : \n");
	goToxy(49, 6);
	printf("NOTICE!: Do not use space betwin words");
	goToxy(17, 7);
	printf("Chosse betwin : ");
	printf("Current-loan-account, ");
	printf("savings-loan-account, ");
	printf("short-term-investment, ");
	printf("Long-term-investment");
	goToxy(55, 9);
	scanf_s("%29s", u1.typeAccount, (unsigned)_countof(u1.typeAccount));
	

	system("cls");  // Take User name
	goToxy(55, 5);
	printf("Enter your user name : ");
	scanf_s("%49s", u1.userName, (unsigned)_countof(u1.userName));

	// Writing to the file
	fwrite(&u1, sizeof(u1), 1, fptr);
	
	// Close the file
	fclose(fptr);
	
	err = fopen_s(&fptr, "userpass.txt", "ab");

	if (err != 0 || fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	system("cls");  // Take Password
	goToxy(55, 5);
	printf("Enter your password : ");
	scanf_s("%49s", p1.userPass, (unsigned)_countof(p1.userPass));

	// Writing to the file
	fwrite(&p1, sizeof(p1), 1, fptr);

	// Close the file
	fclose(fptr);

	// Calling accountCreated function
	accountCreated();
}

// Successful account creation
void accountCreated()
{
	int i;
	char enter;

	system("cls");
	goToxy(63, 5);
	printf("**PLEASE WAIT**");
	
	goToxy(30, 7);
	printf("YOUR DATA IS PROCESSING");
	for (i = 0; i < 60; i++)
	{
		delay(0.1);
		printf(".");
	}
	
	goToxy(55, 10);
	printf("**ACCOUNT CREATED SUCCESSFULLY**");

	goToxy(55, 12);
	printf("Press enter to open login window!");

	enter = getch();
	accountLogin();
}

// Log in function to check user name & pass word
void accountLogin()
{
	int i, i1 = 0, i2;
	char enter;
	char ch, ch1;
	char userName[50];
	char userPass[50];
	struct usersData u1;
	struct usersPassword p1;
	bool bUserName = false;
	bool bUserPass = false;
	FILE* fptr;

	errno_t err;
	errno = 0;
	char buffer[50];

	// Open file to read from it
	err = fopen_s(&fptr, "userdata.txt", "rb");

	if (err != 0 || fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	system("cls");
	goToxy(60, 5);
	printf(" ACOUNT LOGIN");
	
	goToxy(10, 6);
	for (i = 0; i < 112; i++)
	{
		printf("*");
	}

	goToxy(60, 8);
	printf("Enter login info : ");

	goToxy(60, 10);
	printf("Enter your User name : ");  // Take user name
	while (i1 != 49)
	{
		ch = getch();
		if (ch == 13)
		{
			userName[i1] = '\0';
			break;
		}
		else
		{
			userName[i1++] = ch;
			printf("%c", ch);
		}
	}

	while (fread(&u1, sizeof(u1), 1, fptr))
	{
		if (strcmp(userName, u1.userName) == 0)  // Compare user name
		{
			bUserName = true;
			uAccountMenuNew(userName);
		}
	}

	// Close the file
	fclose(fptr);

	// Open file to read from it
	err = fopen_s(&fptr, "userpass.txt", "rb");

	if (err != 0 || fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	goToxy(60, 11);
	printf("Enter your User password : ");  // Take user password in form '*'
	i1 = 0;
	while (i1 != 49)
	{
		ch1 = getch();
		if (ch1 == 13)
		{
			userPass[i1] = '\0';
			break;
		}
		else
		{
			userPass[i1++] = ch1;
			printf("*");
		}
	}
	
	//goToxy(60, 13);

	while (fread(&p1, sizeof(p1), 1, fptr))
	{
		if (strcmp(userPass, p1.userPass) == 0)  // Compare user password
		{
			bUserPass = true;
		}
		//else { printf("%d\n", strcmp(userPass, p1.userPass)); }
	}

	// Close the file
	fclose(fptr);

	if (bUserName == true && bUserPass == true)
	{
		goToxy(60, 13);
		printf("User name correct.\n");
		goToxy(60, 14);
		printf("User pass correct.\n");

		delay(3.0);
		system("cls");
		goToxy(63, 5);
		printf("**PLEASE WAIT**");

		goToxy(30, 7);
		printf("FETCHING ACCOUNT DATA");
		for (i2 = 0; i2 < 60; i2++)
		{
			delay(0.1);
			printf(".");
		}

		goToxy(60, 9);
		printf("**LOGIN SUCCESSFUL**");

		goToxy(50, 12);
		printf("Press enter to open your account window!");

		enter = getch();
		uAccountMenu(userName);

	}
	else if (bUserName == false && bUserPass == true) 
	{
		goToxy(60, 13);
		printf("User name incorrect!\n"); 

		delay(5.0);
		system("cls");
		startMenu();
		choice();
	}
	else if (bUserName == true && bUserPass == false) 
	{
		printf(" \"%s\"", userPass);
		goToxy(60, 13);
		printf("User pass incorrect!\n"); 

		delay(5.0);
		system("cls");
		startMenu();
		choice();
	}
	else 
	{ 
		printf(" \"%s\"", userPass);
		goToxy(60, 13);
		printf("Both (User name, User pass) incorrect!\n"); 

		delay(5.0);
		system("cls");
		startMenu();
		choice();
	}
	
}
