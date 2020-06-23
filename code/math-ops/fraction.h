#ifndef _FRACTION_
#define _FRACTION_

#include "io_utils.h"

class Fraction
{
public:
    Fraction() : n(0), d(0) {}

    void input(int x, int y, const char* str);
    void print() const;

    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator*(const Fraction& f);
    Fraction operator/(const Fraction& f);

private:
    int n;  // numerator
    int d;  // denominator
};

void Fraction::input(int x, int y, const char* str)
{
    while (1)
    {
        gotoxy(x, y);
        cout << str;
        cin.unsetf(ios::skipws);

        while (1)
        {
            gotoxy(x, y);
            cout << str;

            char slash = '\0';
            cin >> n >> slash >> d;
            if (slash != '/')
            {
                cin.clear();
                cin.ignore(10, '\n');

                invalidInput(x + 30, y + 1, "Invalid separator! Use front slash [/]!");

                gotoxy(x, y); clreol();
                gotoxy(x + 30, y + 1); clreol();
            }
            else if (d == 0)
            {
                invalidInput(15, 10, "Denominator cannot be zero. Press any key to continue...");
                gotoxy(15, 10); delline();
                gotoxy(20,  8); delline();
            }
            else
            {
                break;
            }
        }

        if (cin.good())
        {
            cin.ignore(10, '\n');
            break;
        }

        cin.clear();
        cin.ignore(10, '\n');

        invalidInput(x + 30, y + 1);
        gotoxy(x, y); clreol();
        gotoxy(x + 30, y + 1); clreol();
    }
}

void Fraction::print() const
{
    printf("%d / %d\n", n, d);
}

Fraction Fraction::operator+(const Fraction& f)
{
    Fraction c;
    c.n = (n * f.d) + (f.n * d);
    c.d = d * f.d;

    int maxDivisor = (c.n > c.d) ? c.d / 2 : c.n / 2;
    maxDivisor = (maxDivisor < 0) ? -maxDivisor : maxDivisor;
    for (int i = 2; i <= maxDivisor; ++i)
    {
        if (((c.n % i) == 0) && ((c.d % i) == 0))
        {
            c.n /= i;
            c.d /= i;
            i = 1;
        }
    }

    return c;
}

Fraction Fraction::operator-(const Fraction& f)
{
    Fraction c;
    c.n = (n * f.d) - (f.n * d);
    c.d = d * f.d;

    int maxDivisor = (c.n > c.d) ? c.d / 2 : c.n / 2;
    maxDivisor = (maxDivisor < 0) ? -maxDivisor : maxDivisor;
    for (int i = 2; i <= maxDivisor; ++i)
    {
        if (((c.n % i) == 0) && ((c.d % i) == 0))
        {
            c.n /= i;
            c.d /= i;
            i = 1;
        }
    }

    return c;
}

Fraction Fraction::operator*(const Fraction& f)
{
    Fraction c;
    c.n = n * f.n;
    c.d = d * f.d;

    int maxDivisor = (c.n > c.d) ? c.d / 2 : c.n / 2;
    maxDivisor = (maxDivisor < 0) ? -maxDivisor : maxDivisor;
    for (int i = 2; i <= maxDivisor; ++i)
    {
        if (((c.n % i) == 0) && ((c.d % i) == 0))
        {
            c.n /= i;
            c.d /= i;
            i = 1;
        }
    }

    return c;
}

Fraction Fraction::operator/(const Fraction& f)
{
    Fraction c;
    c.n = n * f.d;
    c.d = f.n * d;

    int maxDivisor = (c.n > c.d) ? c.d / 2 : c.n / 2;
    maxDivisor = (maxDivisor < 0) ? -maxDivisor : maxDivisor;
    for (int i = 2; i <= maxDivisor; ++i)
    {
        if (((c.n % i) == 0) && ((c.d % i) == 0))
        {
            c.n /= i;
            c.d /= i;
            i = 1;
        }
    }

    return c;
}

#endif // _FRACTION_