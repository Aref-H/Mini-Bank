/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "resizingFunc.h"

// Declaring a function to get console metrics
void consoleMetrics()
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	printf("Screen width is equal to %d\n", screenWidth);
	printf("Screen height is equal to %d\n", screenHeight);
}

// Declaring resizing function for setting window position
void editConsole()
{
	HWND hWnd = GetConsoleWindow();
	MoveWindow(hWnd, 341, 233, 1024, 600, TRUE);
}
