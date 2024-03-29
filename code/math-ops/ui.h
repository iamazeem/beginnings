#ifndef _UI_
#define _UI_

#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include "io_utils.h"
#include "ui.h"

// Prototypes

void drawBismillah();
void drawStartupScreen();
void drawBorder();
void drawExitScreen();
void countDown();
bool confirmExit();
void bye();

int confirm(const int x, const int y);

// Definitions

void drawBismillah()
{
    clrscr();
    textmode(C4350);
    clrscr();
    _setcursortype(_NOCURSOR);

    const char* bismillahArt[] = {
        "浜様様様様様様様様様様様様様様様様様様様様様様様様様様�",
        "�                                                     �",
        "�                  樛樛樛�  �  �  �  �  樛樛  �  �  � �",
        "�        樛樛      �     �  �  �  �  �  �  �  �  �  � �",
        "� 樛樛樛樂  桀樛樛樛樛樛樂  �  �  �  �  �  �  �  �  � �",
        "� �      桀樂               �  �  �  �  �  �  �  �  � �",
        "� �               � �       �  �  �  �  �  �  �  �  � �",
        "� �              �          �  �  �  �  �  �  �  �  � �",
        "� �        樛樛  �  桎烝烝� �  �  �  �  �  �  �  �  � �",
        "� � � � 桀樂  桀樛樛樛樛樛� �  �  �  �  �  �  �  �  � �",
        "� � �   �  桀樂          樛樂     �  �  �  �  �  �  � �",
        "� � 桀樛� 樛樛樛樛樛樛樛樂     桎烝  �  �  烝烝烝�  � �",
        "� �  樛樛 樛樛樛樛樛樛樛樛樛樛樂                    � �",
        "� 樛樂  桀樛樛樛樛樛樛樛樛樛樛樛樛樛樛樛樛樂樛桀樂樛� �",
        "� �  桀樂                                          �  �",
        "�                                                     �",
        "藩様様様様様様様様様様様様様様様様様様様様様様様様様様�",
        NULL
    };

    for (int row = 0; bismillahArt[row]; ++row)
    {
        print(14, 13 + row, bismillahArt[row], LIGHTGREEN);
        beep();
    }

    delay(200);

    for (int i = 0; i < 30; ++i)
    {
        gotoxy(1, 1); delline();
        delay(100);
    }
}

void drawStartupScreen()
{
    textmode(C80);
    _setcursortype(_NOCURSOR);
    delay(1000);
    beep();

    const char* mathArt[] = {
        "毟栲       毟栲     栩     栩栩栩栩栩 毟栲    毟栲",
        " 栩 栩   栩 栩    栩  栩   栩  栩  栩  栩      栩",
        " 栩  栩 栩  栩   栩    栩      栩      栩      栩",
        " 栩   炳�   栩  栩  栩  栩     栩      栩 毟栲 栩",
        " 栩         栩  栩      栩     栩      栩      栩",
        " 栩         栩  栩      栩     栩      栩      栩",
        "毟栲       毟栲毟栲    毟栲   毟栲    毟栲    毟栲",
        NULL
    };

    for (int row = 0; mathArt[row]; ++row)
    {
        print(16, 3 + row, mathArt[row], BLUE);
        delay(200);
    }

    print(16, 11, "様様様様様様様様様様様様様様様様様様様様様様様様様", WHITE);
    print(16, 12, "               O P E R A T I O N S                ", LIGHTRED);
    print(16, 13, "様様様様様様様様様様様様様様様様様様様様様様様様様", WHITE);
    print(16, 14, "  Created by AZEEM SAJID (azeem.sajid@gmail.com)  ", LIGHTBLUE);
    print(16, 15, "様様様様様様様様様様様様様様様様様様様様様様様様様", WHITE);

    beep();
    print(28, 19, "Press any key to continue...", YELLOW); getch();
    gotoxy(28, 19); delline();

    print(29, 20, "Please wait...", LIGHTGRAY);
    print(29, 21, "浜様様様様様様様様様融", DARKGRAY);
    print(29, 22, "�                    �", DARKGRAY);
    print(29, 23, "藩様様様様様様様様様夕", DARKGRAY);
    print(31, 22, "臼臼臼臼臼臼臼臼臼", LIGHTGRAY);

    for (int c = 31; c <= 48; ++c)
    {
        print(c, 22, "�", YELLOW);
        delay(100);
    }
}

void drawBorder()
{
    _setcursortype(_NOCURSOR);
    clrscr();

    const int color = LIGHTRED;

    print( 4,  2, "浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融", color);

    print(20,  4, "浜様様様様様様様様様様様様様様様様様様様�", color);
    print(20,  5, "�                                       �", color);
    print(20,  6, "藩様様様様様様様様様様様様様様様様様様様�", color);

    print(20, 17, "浜様様様様様様様様様様様様様様様様様様様�", color);
    print(20, 18, "�                                       �", color);
    print(20, 19, "藩様様様様様様様様様様様様様様様様様様様�", color);
    print(21, 18, "    Select your option:    ", RED);

    for (int h = 0, r = 3; h <= 18; ++r, ++h)
    {
        print(4,  r, '�', color);
        print(77, r, '�', color);
    }

    print(4,  22, "麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様郵", color);
    print(4,  23, "�                         Created by                                     �", color);
    print(4,  24, "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕", color);
    print(41, 23, "Azeem Sajid", LIGHTBLUE);

    print(4, 25, "Navigate ", DARKGRAY); print("[UP | DOWN | OPTION {A|B ...}]", DARKGRAY);
    print(" - ", WHITE);
    print("SELECT ", DARKGRAY); print("[ENTER]", DARKGRAY);
    print(" - ", WHITE);
    print("BACK/EXIT ", DARKGRAY); print("[ESC]", DARKGRAY);
}

void drawExitScreen()
{
    _setcursortype(_NOCURSOR);
    clrscr();

    const char* exitArt[] = {
        "栩栩栩栩栩  栩栩   栩栩   栩栩  栩栩栩栩栩栩",
        " 栩     栩   栩     栩     栩   栩   栩   栩",
        " 栩           栩   栩      栩        栩",
        " 栩栩栩        栩越�       栩        栩",
        " 栩           栩   栩      栩        栩",
        " 栩     栩   栩     栩     栩        栩",
        "栩栩栩栩栩  栩栩   栩栩   栩栩      栩栩",
        "\n",
        "浜様様様様様様様様様様様様様様様様様様様様融",
        "�                                          �",
        "藩様様様様様様様様様様様様様様様様様様様様夕",
        NULL
    };

    for (int row = 0; exitArt[row]; ++row)
    {
        print(18, 4 + row, exitArt[row], BROWN);
    }

    print(24, 13, "Are you sure to exit (", WHITE); print("Y", RED); print("/", WHITE); print("N", RED); print(")?   ", WHITE);
    _setcursortype(_NORMALCURSOR);
}

void countDown()
{
    _setcursortype(_NOCURSOR);

    print(32, 17, "PLEASE WAIT...", YELLOW);

    for (int i = 10; i >= 0; --i)
    {
        gotoxy(38, 19); cprintf("%d", i);
        delay(100);
        gotoxy(38, 19); delline();
    }

    for (int r = 0; r > 25; --r)
    {
        gotoxy(1, 1); delline();
        delay(50);
    }
}

bool confirmExit()
{
    drawExitScreen();

    print(12, 20, "The program will quit automatically after      seconds", LIGHTBLUE);

    int i = 10;
    while (!kbhit() && i >= 0)
    {
        gotoxy(55, 20); cprintf("%2d", i);
        gotoxy(54, 13);

        delay(500);

        if (kbhit()) break;

        delay(500);
        --i;
    }

    gotoxy(12, 20); clreol();

    if (i == -1)
    {
        countDown();
        return true;
    }

	_setcursortype(_NORMALCURSOR);

    do
    {
        gotoxy(54, 13);

        const char choice = getch();
        if (isalpha(choice))
        {
            switch (toupper(choice))
            {
            case 'Y':
                print(54, 13, "Y", WHITE);
                countDown();
                return true;

            case 'N':
                print(54, 13, "N", WHITE);
                return false;

            default:
                beep();
                break;
            }
        }
    } while (1);
}

void bye()
{
    _setcursortype(_NOCURSOR);
    clrscr();

    const char* byeArt[] = {
        "桍毫毟     渟          桍   桍毫毫毫�",
        "毫    毫     栩      栩     毫",
        "毫    毫       桍  渟       毫",
        "毫 栩�          栩桍        毫桍毫",
        "毫    毫         毫         毫",
        "毫     �         毫         毫             槹�",
        "毫    毫         毫         毫           槹槹槹�",
        "桍毫毟          栩桍        桍毫毫毟�  槹槹槹槹槹�",
        NULL
    };

    for (int row = 0; byeArt[row]; ++row)
    {
        print(18, 15 + row, byeArt[row], DARKGRAY);
    }

    print(33, 15, "Bye", LIGHTGRAY, BLINK);
    print(35, 16, "Bye", LIGHTGRAY, BLINK);

    print( 2, 23, "浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融", RED);
    print( 2, 24, "�                                                                            �", RED);
    print( 2, 25, "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕", RED);
    print(12, 24, "Program is now terminated.", YELLOW); print("  Press any key to continue", LIGHTBLUE);

    // dots: loading effect
    int n = 0;
    while (!kbhit())
    {
        gotoxy(65, 24); printf("      ");
        n = (n == 4) ? 0 : ++n;

        for (int sp = 0; sp <= n; ++sp)
        {
            print(65 + sp, 24, ".", YELLOW);
        }

        printf(" ");
        delay(200);
    }

    // disappear down effect
    for (int i = 0; i < 12; ++i)
    {
        gotoxy(1, 1); insline();
        delay(100);
    }

    resetScreen();

    printf("For any feedback, email me at: azeem.sajid@gmail.com");
}

int confirm(const int x, const int y)
{
    beep();

    print(x, y, "Do you want to continue (", YELLOW);
    print("Yes", RED);
    print("/", YELLOW);
    print("Space", RED);
    print(")(", YELLOW);
    print("No", RED);
    print("/", YELLOW);
    print("ESC", RED);
    print(")... ", YELLOW);

    return getch();
}

#endif // _UI_