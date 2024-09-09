/* In general it's good to include also the header of
   the current .c, to avoid repeating the prototypes */
#include "makeDelay.h"

void delay(double numOfSeconds)
{
	// Converting time into milli_seconds
	double miliSecond = 1000 * numOfSeconds;

	// Storing start time
	clock_t startTime = clock();

	while (clock() < startTime + miliSecond);
}