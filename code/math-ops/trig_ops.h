#ifndef _TRIGONOMETRIC_OPS_
#define _TRIGONOMETRIC_OPS_

#include <math.h>
#include "io_utils.h"
#include "menu.h"

struct Trigonometric
{
    static void menu();

    struct Sin
    {
        static void menu();

        static void sinCos();
        static void sinHyp();
        static void sinInv();
    };

    struct Cos
    {
        static void menu();

        static void cosSec();
        static void cosHyp();
        static void cosInv();
    };

    struct Tan
    {
        static void menu();

        static void tanCot();
        static void tanHyp();
        static void tanInv();
    };
};

void Trigonometric::menu()
{
    const MenuItem items[] =
    {
        { 29,  5, "TRIGONOMETRIC OPERATIONS", NO_OP },
        { 21,  9, " Sine Functions ", Sin::menu },
        { 21, 11, " Cosine Functions ", Cos::menu },
        { 21, 13, " Tangent Functions ", Tan::menu },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

// Sin

void Trigonometric::Sin::menu()
{
    const MenuItem items[] =
    {
        { 33,  5, "Sine Functions", NO_OP },
        { 21,  9, " Sine é, Cosecant é ", Sin::sinCos },
        { 21, 11, " Sine Hyperbolic é ", Sin::sinHyp },
        { 21, 13, " Sine Inverse é ", Sin::sinInv },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void Trigonometric::Sin::sinCos()
{
    do
    {
        clrscr();
        print(30, 5, "± Sine é, Cosecant é ±", YELLOW);

        double c = 0.0;
        input(24, 9, "Enter a number: ", c);
        const double r = c * (3.14 / 180);
        const double R = sin(r);
        gotoxy(24, 12); cprintf("The value of Sin   é  is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Cosec é  is: %08lf", 1 / R);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Sin::sinHyp()
{
    do
    {
        clrscr();
        print(30, 5, "± Sine Hyperbolic é ±", YELLOW);

        double c = 0.0;
        input(24, 9, "Enter a number: ", c);
        const double r = c * (3.14 / 180);
        const double R = sin(r);
        const double H = sinh(r);
        gotoxy(24, 12); cprintf("The value of Sin  é is: %08lf", R);
        gotoxy(24, 14); cprintf("The value of Sinh é is: %08lf", H);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Sin::sinInv()
{
    do
    {
        clrscr();
        print(30, 5, "± Sine Inverse é ±", YELLOW);

        double c = 0.0;
        input(24, 9, "Enter a number: ", c);
        const double r = c * (3.14 / 180);
        const double R = sin(r);
        const double I = asin(R);
        gotoxy(24, 12); cprintf("The value of Sin é         is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Sin Inverse é is: %08lf", I);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

// Cos

void Trigonometric::Cos::menu()
{
    const MenuItem items[] =
    {
        { 33,  5, "Cosine Functions", NO_OP },
        { 21,  9, " Cosine é, Secant é ", Cos::cosSec },
        { 21, 11, " Cosine Hyperbolic é ", Cos::cosHyp },
        { 21, 13, " Cosine Inverse é ", Cos::cosInv },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void Trigonometric::Cos::cosSec()
{
    do
    {
        clrscr();
        print(30, 5, "± Cosine é, Secant é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = cos(r);
        gotoxy(24, 12); cprintf("The value of Cos é  is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Sec é  is: %08lf", 1 / R);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Cos::cosHyp()
{
    do
    {
        clrscr();
        print(30, 5, "± Cosine Hyperbolic é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = cos(r);
        const double H = cosh(r);
        gotoxy(24, 12); cprintf("The value of Cos  é is: %08lf", R);
        gotoxy(24, 14); cprintf("The value of Cosh é is: %08lf", H);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Cos::cosInv()
{
    do
    {
        clrscr();
        print(30, 5, "± Sine Inverse é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = cos(r);
        const double I = acos(R);
        gotoxy(24, 12); cprintf("The value of Cos é         is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Cos Inverse é is: %08lf", I);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

// Tan

void Trigonometric::Tan::menu()
{
    const MenuItem items[] =
    {
        { 33,  5, "Tangent Functions", NO_OP },
        { 21,  9, " Tangent é, Cotangent é ", Tan::tanCot },
        { 21, 11, " Tangent Hyperbolic é ", Tan::tanHyp },
        { 21, 13, " Tangent Inverse é ", Tan::tanInv },
        { 21, 15, " BACK (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);
    menu.start();
}

void Trigonometric::Tan::tanCot()
{
    do
    {
        clrscr();
        print(30, 5, "± Tangent é, Cotangent é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = tan(r);
        gotoxy(24, 12); cprintf("The value of Tan é  is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Cot é  is: %08lf", 1 / R);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Tan::tanHyp()
{
    do
    {
        clrscr();
        print(30, 5, "± Tangent Hyperbolic é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = tan(r);
        const double H = tanh(r);
        gotoxy(24, 12); cprintf("The value of Tan  é is: %08lf", R);
        gotoxy(24, 14); cprintf("The value of Tanh é is: %08lf", H);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

void Trigonometric::Tan::tanInv()
{
    do
    {
        clrscr();
        print(30, 5, "± Tangent Inverse é ±", YELLOW);

        double num = 0.0;
        input(24, 9, "Enter a number: ", num);

        const double r = num * (3.14 / 180);
        const double R = tan(r);
        const double I = atan(R);
        gotoxy(24, 12); cprintf("The value of Tan é         is: %08lf", R);
        gotoxy(24, 13); cprintf("The value of Tan Inverse é is: %08lf", I);

    } while (confirm(15, 16) != ESC);

    drawBorder();
}

#endif // _TRIGONOMETRIC_OPS_
