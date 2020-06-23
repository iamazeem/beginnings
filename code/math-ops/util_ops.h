#ifndef _UTILITY_OPS_
#define _UTILITY_OPS_

#include "io_utils.h"
#include "menu.h"
#include "frac_ops.h"

struct Utils
{
    static void menu();

    static void table();
    static void ascii();
};

void Utils::menu()
{
    const MenuItem items[] =
    {
        { 36,  5, "UTILITIES", NO_OP },
        { 21,  9, " Table ", table },
        { 21, 11, " ASCII Equivalent ", ascii },
        { 21, 13, " Fractional Arithmetic ", FractionalOps::menu },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void Utils::table()
{
    do
    {
        clrscr();
        print(30, 5, "± TABLE ±", YELLOW);

        int num = 0;
        int start = 0;
        int end = 0;

        input(20,  8, "Enter table   number (enter 0 to quit):  ", num);
        if (num == 0) break;

        input(20,  9, "Enter starting value (enter 0 to quit):  ", start);
        if (start == 0) break;

        input(20, 10, "Enter ending   value (enter 0 to quit):  ", end);
        if (end == 0) break;

        cprintf("\n");

        for (int count = 0; start <= end; ++count, ++start)
        {
            printf("\t\t\t  %d x %d  =  %d\n", num, start, num * start);

            if (count == 14)
            {
                count = 0;
                print(15, 25, "Press any key to continue...", YELLOW); getch();
                clrscr();
                printf("\n\n\n\n\n\n");
            }
        }
    } while (confirm(15, 24) != ESC);

    drawBorder();
}

void Utils::ascii()
{
    do
    {
        clrscr();
        print(30, 5, "± ASCII Equavilent ±", YELLOW);

        int num = 0;
        input(24, 9, "Enter a number: ", num);

        gotoxy(24, 12); cprintf("The ASCII equavilent is: %c", num);

    } while (confirm(15, 14) != ESC);

    drawBorder();
}

#endif // _UTILITY_OPS_
