#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    char name[10];
    getch();

    printf("Enter your name :\n");
    fgets(name, 9, stdin);
    printf("%s", name);

    return 0;
}

