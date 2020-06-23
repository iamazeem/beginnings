#ifndef _IO_UTILS_
#define _IO_UTILS_

#include <conio.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

#define NO_BLINK    0

// Prototypes

void setColor(const int fgcolor, const int blink = NO_BLINK);
void resetColors();
void resetScreen();

void print(const char ch, const int fgcolor, const int blink = NO_BLINK);
void print(const char* str, const int fgcolor = WHITE, const int blink = NO_BLINK);
void print(const char* str, const int fgcolor, const int bgcolor, const int blink);
void print(const char* str1, const char* str2, const int fgcolor1, const int fgcolor2);

void print(const int x, const int y, const char ch, const int fgcolor, const int blink = NO_BLINK);
void print(const int x, const int y, const char* str, const int fgcolor = WHITE, const int blink = NO_BLINK);
void print(const int x, const int y, const char* str, const int fgcolor, const int bgcolor, const int blink);
void print(const int x, const int y, const char* str1, const char* str2, const int fgcolor1, const int fgcolor2);

template <class T>
void input(int x, int y, char* str, T& t);

void beep();
void invalidInput(int x, int y, const char* msg = NULL);

// Definitions

void setColor(const int fgcolor, const int blink)
{
    const int color = (blink == BLINK ? fgcolor + BLINK : fgcolor);
    textcolor(color);
}

void resetColors()
{
    textcolor(WHITE);
    textbackground(BLACK);
}

void resetScreen()
{
    resetColors();
    _setcursortype(_NORMALCURSOR);
    clrscr();
}

void print(const char ch, const int fgcolor, const int blink)
{
    setColor(fgcolor, blink);
    cprintf("%c", ch);
    resetColors();
}

void print(const char* str, const int fgcolor, const int blink)
{
    setColor(fgcolor, blink);
    cprintf(str);
    resetColors();
}

void print(const char* str, const int fgcolor, const int bgcolor, const int blink)
{
    textbackground(bgcolor);
    print(str, fgcolor, blink);
}

void print(const char* str1, const char* str2, const int fgcolor1, const int fgcolor2)
{
    print(str1, fgcolor1);
    print(str2, fgcolor2);
}

void print(const int x, const int y, const char ch, const int fgcolor, const int blink)
{
    gotoxy(x, y);
    print(ch, fgcolor, blink);
}

void print(const int x, const int y, const char* str, const int fgcolor, const int blink)
{
    gotoxy(x, y);
    print(str, fgcolor, blink);
}

void print(const int x, const int y, const char* str, const int fgcolor, const int bgcolor, const int blink)
{
    gotoxy(x, y);
    print(str, fgcolor, bgcolor, blink);
}

void print(const int x, const int y, const char* str1, const char* str2, const int fgcolor1, const int fgcolor2)
{
    gotoxy(x, y);
    print(str1, fgcolor1);
    print(str2, fgcolor2);
}

template <class T>
void input(int x, int y, char* str, T& t)
{
    bool isValidInput = false;
    while (!isValidInput)
    {
        print(x, y, str);
        cin.unsetf(ios::skipws);

        cin >> t;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(10, '\n');

            invalidInput(x + 30, y + 1);

            gotoxy(x, y); clreol();
            gotoxy(x + 30, y + 1); clreol();
        }
        else
        {
            cin.ignore(10, '\n');
            isValidInput = true;
        }
    }
}

void beep()
{
    sound(2500);
    delay(100);
    nosound();
}

void invalidInput(int x, int y, const char* msg)
{
    beep();
    print(x, y, msg ? msg : "Invalid input!", YELLOW);
    getch();
}

#endif // _IO_UTILS_