#ifndef _FRACTIONAL_OPS_
#define _FRACTIONAL_OPS_

#include "io_utils.h"
#include "menu.h"
#include "fraction.h"

struct FractionalOps
{
    static void menu();

    static void add();
    static void sub();
    static void mul();
    static void div();
};

void FractionalOps::menu()
{
    const MenuItem items[] =
    {
        { 31,  5, "Fractional Arithmetic", NO_OP },
        { 21,  8, " Addition ", add },
        { 21, 10, " Subtraction ", sub },
        { 21, 12, " Multiplication ", mul },
        { 21, 14, " Division ", div },
        { 21, 16, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void FractionalOps::add()
{
    do
    {
        clrscr();
        print(25, 5, "± Adition Of Two Fractions ±", YELLOW);

        Fraction f1;
        Fraction f2;

        f1.input(20, 8, "Enter first  fraction (a/b):  ");
        f2.input(20, 9, "Enter second fraction (a/b):  ");

        const Fraction result = f1 + f2;
        print(41, 12, "Answer: "); result.print();

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void FractionalOps::sub()
{
    do
    {
        clrscr();
        print(25, 5, "± Subtraction Of Two Fractions ±", YELLOW);

        Fraction f1;
        Fraction f2;

        f1.input(20, 8, "Enter first  fraction (a/b):  ");
        f2.input(20, 9, "Enter second fraction (a/b):  ");

        const Fraction result = f1 - f2;
        print(41, 12, "Answer: "); result.print();

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void FractionalOps::mul()
{
    do
    {
        clrscr();
        print(25, 5, "± Multiplication Of Two Fractions ±", YELLOW);

        Fraction f1;
        Fraction f2;

        f1.input(20, 8, "Enter first  fraction (a/b):  ");
        f2.input(20, 9, "Enter second fraction (a/b):  ");

        const Fraction result = f1 * f2;
        print(41, 12, "Answer: "); result.print();

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

void FractionalOps::div()
{
    do
    {
        clrscr();
        print(25, 5, "± Divison Of Two Fractions ±", YELLOW);

        Fraction f1;
        Fraction f2;

        f1.input(20, 8, "Enter first  fraction (a/b):  ");
        f2.input(20, 9, "Enter second fraction (a/b):  ");

        const Fraction result = f1 / f2;
        print(41, 12, "Answer: "); result.print();

    } while (confirm(15, 15) != ESC);

    drawBorder();
}

#endif // _FRACTIONAL_OPS_
