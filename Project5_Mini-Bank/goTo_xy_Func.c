/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "goTo_xy_Func.h"

// Declaring goToxy function for setting cursor position
void goToxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
