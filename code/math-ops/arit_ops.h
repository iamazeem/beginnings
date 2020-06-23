#ifndef _ARITHMETIC_OPS_
#define _ARITHMETIC_OPS_

#include <math.h>
#include "io_utils.h"
#include "menu.h"
#include "ui.h"

struct Arithmetic
{
    static void menu();

    static void add();
    static void sub();
    static void mul();
    static void div();
    static void square();
    static void squareRoot();
    static void cube();
};

void Arithmetic::menu()
{
    const MenuItem items[] =
    {
        { 31,  5, "ARITHMETIC OPERATIONS", NO_OP },
        { 21,  8, " Addition ", add },
        { 21,  9, " Subtraction ", sub },
        { 21, 10, " Multiplication ", mul },
        { 21, 11, " Division ", div },
        { 21, 12, " Square ", square },
        { 21, 13, " Square Root ", squareRoot },
        { 21, 14, " Cube ", cube },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void Arithmetic::add()
{
    do
    {
        clrscr();
        print(30, 5, "± Addition ±", YELLOW);

        double num = 1.0;
        double ans = 0.0;

        int row = 9;
        while (num > 0.0)
        {
            input(20, row, "Enter a number (input stops at 0): ", num);
            if (num == 0) break;

            if (row >= 25)
            {
                gotoxy(1, 1); delline();
                --row;
                gotoxy(20, row);
            }
            else
            {
                ++row;
            }
            ans += num;
        }

        clrscr();
        gotoxy(24, 12); cprintf("Sum of all values  = %f\n", ans);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::sub()
{
    do
    {
        clrscr();
        print(30, 5, "± Subtraction ±", YELLOW);

        double num1 = 0.0;
        double num2 = 0.0;

        input(24, 9, "Enter first  number (enter 0 to quit):  ", num1);
        if (num1 == 0) break;

        input(24, 10, "Enter second number (enter 0 to quit):  ", num2);
        if (num2 == 0) break;

        gotoxy(24, 12); cprintf("Difference of %f - %f is: %f", num1, num2, num1 - num2);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::mul()
{
    do
    {
        clrscr();
        print(30, 5, "± Multiplication ±", YELLOW);

        double num = 1.0;
        double ans = 0.0;

        int row = 9;
        while (num != 0.0)
        {
            input(20, row, "Enter a number (input stops at 0): ", num);
            if (num == 0.0) break;

            if (row >= 25)
            {
                gotoxy(1, 1); delline();
                --row;
                gotoxy(20, row);
            }
            else
            {
                row++;
            }
            ans *= num;
        }

        clrscr();
        gotoxy(24, 12); cprintf("Product of all values is = %f\n", ans);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::div()
{
    do
    {
        clrscr();
        print(30, 5, "± Division ±", YELLOW);

        double num1 = 0.0;
        double num2 = 0.0;

        input(24,  9, "Enter first  number: ", num1);
        input(24, 10, "Enter second number: ", num2);

        if (num2 == 0)
        {
            invalidInput(15, 12, "Denominator cannot be zero! Press any key to continue...");
            continue;
        }

        gotoxy(20, 12); cprintf("Quotient  of %f / %f is: %f", num1, num2, num1 / num2);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::square()
{
    do
    {
        clrscr();
        print(30, 5, "± Square (ný) ±", YELLOW);

        double num = 0.0;

        input(24, 9, "Enter a number (enter 0 to quit):  ", num);
        if (num == 0) break;

        gotoxy(24, 12); cprintf("Square of %f is: %f", num, num * num);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::squareRoot()
{
    do
    {
        clrscr();
        print(30, 5, "± Square Root ±", YELLOW);

        double num = 0.0;

        input(24, 9, "Enter a number (enter 0 to quit):  ", num);
        if (num == 0.0) break;

        if (num < 0)
        {
            invalidInput(4, 13, "Negative value is not allowed! Press any key to continue...");
            continue;
        }

        gotoxy(24, 12); cprintf("Square Root of %lf is: %lf", num, sqrt(num));

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void Arithmetic::cube()
{
    do
    {
        clrscr();
        print(30, 5, "± Cube ±", YELLOW);

        double num = 0.0;

        input(24, 9, "Enter a  number: ", num);
        gotoxy(24, 12); cprintf("Cube of %f is: %f", num, num * num * num);

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

#endif // _ARITHMETIC_OPS_