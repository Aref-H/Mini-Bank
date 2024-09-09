/*
* project :    Mini banking management system
* Developer :  AREF HEYDARI
* Date :       9/9/2024
*/

// Standard headers
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// Other headers
#include "goTo_xy_Func.h"
#include "resizingFunc.h"
#include "startMenu.h"
#include "userChoice.h"

// Driver function
int main()
{
	// Calling editConsole function
	editConsole();

	// Calling startMenu function 
	startMenu();

	// Calling choice function
	choice();

	return 0;
}
