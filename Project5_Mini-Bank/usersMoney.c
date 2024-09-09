/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "usersMoney.h"

// Function to transfer money 
void transferMoney()
{
	int i;
	FILE* uD_fptr;
	FILE* uM_fptr;
	char userNamef[50];
	char userNamet[50];
	struct usersData u1;
	struct usersMoney m1;

	errno_t err;
	errno_t errr;
	errno = 0;
	char buffer[50];
	
	system("cls");

	// Opening file in read mode to read user's username
	err = fopen_s(&uD_fptr, "userdata.txt", "rb");

	if (err != 0 || uD_fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	// Creating a another file to write amount along with
	// username to which amount is going to be transferred
	errr = fopen_s(&uM_fptr, "usermoney.txt", "ab");

	if (errr != 0 || uM_fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Error : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	goToxy(55, 5);
	printf("***TRANSFER MONEY***");

	goToxy(10, 6);
	for (i = 0; i < 112; i++)
	{
		printf("*");
	}

	goToxy(55, 8);
	printf("From username : ");
	scanf_s("%49s", userNamef, (unsigned)_countof(userNamef));

	goToxy(55, 10);
	printf("To username : ");
	scanf_s("%49s", userNamet, (unsigned)_countof(userNamet));

	// Checking for username if it is present in file or not
	while (fread(&u1, sizeof(u1), 1, uD_fptr))
	{
		if (strcmp(userNamet, u1.userName) == 0)
		{
			strcpy_s(m1.userTo, _countof(m1.userTo), u1.userName);
			strcpy_s(m1.userFrom, _countof(m1.userFrom), userNamef);
		}
	}

	// Taking amout input
	goToxy(55, 12);
	printf("ENTER AMOUNT TO BE TRANSFERRED : ");
	scanf_s("%20d", &m1.userMoney);

	// Writing to file
	fwrite(&m1, sizeof(m1), 1, uM_fptr);

	goToxy(20, 16);
	printf("Transferring amount, please wait");
	for (i = 0; i < 60; i++)
	{
		delay(0.1);
		printf(".");
	}

	system("cls");
	goToxy(55, 5);
	printf("**AMOUNT SUCCESSFULLY TRANSFERRED**");
	delay(3.0);

	system("cls");
	goToxy(55, 5);
	printf("Note : logout to check newest transfer!");
	delay(3.0);

	// Close the file
	fclose(uD_fptr);
	fclose(uM_fptr);
}

// Function to check balance
void checkBalance(char userName[50])
{
	FILE* fptr;
	struct usersMoney m1;
	int sumOfMoney = 0;
	int no = 1;
	char ch;

	errno_t err;
	errno = 0;
	char buffer[50];

	// Opening usermoney.txt file to read records
	err = fopen_s(&fptr, "usermoney.txt", "rb");

	if (err != 0 || fptr == NULL)
	{
		strerror_s(buffer, 50, errno);
		system("cls");
		goToxy(55, 5);
		printf("Erorr : %s\n", buffer);
		exit(EXIT_FAILURE);
	}

	system("cls");
	goToxy(55, 5);
	printf("**TRANSFER RECORDS**");

	goToxy(10, 8);
	printf("no.");

	goToxy(25, 8);
	printf("From user");

	goToxy(60, 8);
	printf("Amount");

	goToxy(100, 8);
	printf("Total amount");

	int numOfLine = 10;

	// Reading user name to get correct data
	while (fread(&m1, sizeof(m1), 1, fptr))
	{
		if (strcmp(userName, m1.userTo) == 0)
		{
			goToxy(10, ++numOfLine);
			printf("%d", no++);

			goToxy(25, numOfLine);
			printf("%s", m1.userFrom);

			goToxy(60, numOfLine);
			printf("%d", m1.userMoney);

			goToxy(100, numOfLine);
			sumOfMoney += m1.userMoney;
			printf("%d", sumOfMoney);
		}
	}

	ch = getch();

	// Closing file after reading from it
	fclose(fptr);
}