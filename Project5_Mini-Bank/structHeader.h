// Include this header file once "#pragma once"
#pragma once

// Creating struct to store data of the user
struct usersData
{
	char userName[50];
	char uFName[20];
	char uLName[20];
	char uNationalCode[15];
	char uFathName[20];
	char uMothName[20];
	char uAddress[50];
	char uPhonNum[15];
	char typeAccount[30];
	int  date, month, year;
};

// Creating struct to keep track of transferred money 
struct usersMoney
{
	char userTo[50];
	char userFrom[50];
	long int userMoney;
};

// creating struct to store users password
struct usersPassword
{
	char userPass[50];
};