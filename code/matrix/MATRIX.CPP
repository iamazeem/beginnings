#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <constrea.h>
#include <dos.h>

int main()
{
    textmode(C80);
    clrscr();

    constream w, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14;
    constream m1, m2, m3, m4, m5, m6, dd, d1, d2, d3, d4, d5, d6, m;
    constream mm1, mm2, mm3, mm4, mm5, mm6;

    w.window(1, 25, 80, 25); textbackground(GREEN); textcolor(BLUE); clrscr(); delay(50);
    w << "                    Created By: AZEEM (azeem.sajid@gmail.com)";

    mm1.window(33, 1, 33, 19); textcolor(GREEN); clrscr();
    mm2.window(36, 1, 36, 19); textcolor(GREEN); clrscr();
    mm3.window(39, 1, 39, 19); textcolor(GREEN); clrscr();
    mm4.window(42, 1, 42, 19); textcolor(GREEN); clrscr();
    mm5.window(45, 1, 45, 19); textcolor(GREEN); clrscr();
    mm6.window(48, 1, 48, 19); textcolor(GREEN); clrscr();

    int i = 0;
    for (i = 0; !kbhit(); ++i)
    {
        if (i == 20) break;
        mm1 << "M" << random(2) << random(2); delay(50);
        mm6 << "X" << random(2) << random(2) << random(2); delay(50);
        mm2 << "A" << random(2) << random(2) << random(2); delay(50);
        mm4 << "R" << random(2) << random(2); delay(50);
        mm3 << "T" << random(2) << random(2) << random(2); delay(50);
        mm5 << "I" << random(2) << random(2); delay(50);
    }

    mm1.clrscr();
    mm2.clrscr();
    mm3.clrscr();
    mm4.clrscr();
    mm5.clrscr();
    mm6.clrscr();

    w1.window(3, 1, 4, 24);     textcolor(GREEN);       clrscr();
    w2.window(78, 1, 79, 24);   textcolor(LIGHTGREEN);  clrscr();
    w3.window(5, 1, 6, 22);     textcolor(LIGHTGREEN);  clrscr();
    w4.window(76, 1, 77, 22);   textcolor(GREEN);       clrscr();
    w5.window(7, 1, 8, 20);     textcolor(GREEN);       clrscr();
    w6.window(74, 1, 75, 20);   textcolor(LIGHTGREEN);  clrscr();
    w7.window(9, 1, 10, 18);    textcolor(LIGHTGREEN);  clrscr();
    w8.window(72, 1, 73, 18);   textcolor(GREEN);       clrscr();
    w9.window(11, 1, 12, 16);   textcolor(GREEN);       clrscr();
    w10.window(70, 1, 71, 16);  textcolor(LIGHTGREEN);  clrscr();
    w11.window(13, 1, 14, 14);  textcolor(LIGHTGREEN);  clrscr();
    w12.window(68, 1, 69, 14);  textcolor(GREEN);       clrscr();
    w13.window(15, 1, 17, 12);  textcolor(GREEN);       clrscr();
    w14.window(66, 1, 67, 12);  textcolor(LIGHTGREEN);  clrscr();

    // Matrix
    m1.window(21, 15, 25, 15); textcolor(LIGHTGREEN);   clrscr();
    m2.window(56, 15, 60, 15); textcolor(LIGHTGREEN);   clrscr();
    m3.window(22, 15, 23, 23); textcolor(LIGHTGREEN);   clrscr();
    m4.window(57, 15, 58, 23); textcolor(LIGHTGREEN);   clrscr();
    m5.window(21, 23, 25, 23); textcolor(LIGHTGREEN);   clrscr();
    m6.window(56, 23, 60, 23); textcolor(LIGHTGREEN);   clrscr();
    dd.window(37, 20, 43, 20); textcolor(LIGHTGREEN);   clrscr();
    d1.window(26, 16, 29, 16); textcolor(LIGHTGREEN);   clrscr();
    d2.window(30, 17, 33, 17); textcolor(LIGHTGREEN);   clrscr();
    d3.window(34, 18, 37, 18); textcolor(LIGHTGREEN);   clrscr();
    d4.window(43, 18, 46, 18); textcolor(LIGHTGREEN);   clrscr();
    d5.window(47, 17, 50, 17); textcolor(LIGHTGREEN);   clrscr();
    d6.window(51, 16, 54, 16); textcolor(LIGHTGREEN);   clrscr();

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 50) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n';
        delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 50) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n'; delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 45) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n' << random(2) << '\n'; delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 40) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w7 << random(2) << '\n' << random(2) << '\n';
        w8 << random(2) << '\n' << random(2) << '\n'; delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 35) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w7 << random(2) << '\n' << random(2) << '\n';
        w8 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w9 << random(2) << '\n' << random(2) << '\n';
        w10 << random(2) << '\n' << random(2) << '\n'; delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 30) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w7 << random(2) << '\n' << random(2) << '\n';
        w8 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w9 << random(2) << '\n' << random(2) << '\n';
        w10 << random(2) << '\n' << random(2) << '\n'; delay(50);
        w11 << random(2) << '\n' << random(2) << '\n';
        w12 << random(2) << '\n' << random(2) << '\n'; delay(50);
    }

    for (i = 0; !kbhit(); ++i)
    {
        if (i == 20) break;
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n' << random(2) << '\n';
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n' << random(2) << '\n';
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n' << random(2) << '\n';
        w7 << random(2) << '\n' << random(2) << '\n';
        w8 << random(2) << '\n' << random(2) << '\n';
        w9 << random(2) << '\n' << random(2) << '\n';
        w10 << random(2) << '\n' << random(2) << '\n';
        w11 << random(2) << '\n' << random(2) << '\n';
        w12 << random(2) << '\n' << random(2) << '\n';
        w13 << random(2) << '\n' << random(2) << '\n';
        w14 << random(2) << '\n' << random(2) << '\n';
    }

    m.window(37, 15, 42, 15); textcolor(LIGHTGREEN); clrscr();
    printf("MATRIX");

    while (!kbhit())
    {
        w1 << random(2) << '\n' << random(2) << '\n';
        w2 << random(2) << '\n';
        w3 << random(2) << '\n' << random(2) << '\n';
        w4 << random(2) << '\n';
        w5 << random(2) << '\n' << random(2) << '\n';
        w6 << random(2) << '\n';
        w7 << random(2) << '\n' << random(2) << '\n';
        w8 << random(2) << '\n';
        w9 << random(2) << '\n' << random(2) << '\n';
        w10 << random(2) << '\n';
        w11 << random(2) << '\n' << random(2) << '\n';
        w12 << random(2) << '\n';
        w13 << random(2) << '\n' << random(2) << '\n';
        w14 << random(2) << '\n';

        m1 << random(2) << random(2) << random(2) << random(2);
        m2 << random(2) << random(2) << random(2) << random(2);
        m3 << random(2) << random(2);
        m4 << random(2) << random(2);
        m5 << random(2) << random(2) << random(2) << random(2);
        m6 << random(2) << random(2) << random(2) << random(2);

        dd << "M"; delay(50);
        dd << "A"; delay(50);
        dd << "T"; delay(50);
        dd << "R"; delay(50);
        dd << "I"; delay(50);
        dd << "X"; delay(50);

        d1 << random(2);
        d2 << random(2);
        d3 << random(2);
        d4 << random(2);
        d5 << random(2);
        d6 << random(2);
    }

    clrscr();
    return 0;
}
