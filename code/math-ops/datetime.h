#ifndef _DATETIME_
#define _DATETIME_

#include "io_utils.h"
#include <stdlib.h>

// Screen coordinates
#define DATE_X      6
#define DATE_Y      23
#define TIME_X      59
#define TIME_Y      23
#define CURSOR_X    48
#define CURSOR_Y    18
#define DELAY_MS    100

// Prototypes

void updateDate();
void updateTime();
void updateDateTime();
void updateDateTimeUntilKbhit();

// Definitions

void updateDate()
{
    static struct date d = {0};
    getdate(&d);

    print(DATE_X, DATE_Y, "Date: ", DARKGRAY);
    cprintf("%d-%d-%d", d.da_day, d.da_mon, d.da_year);
}

void updateTime()
{
    static struct time t = {0};
    gettime(&t);

    if (t.ti_hour > 12)
    {
        t.ti_hour -= 12;
    }

    const char m = (t.ti_hour < 12 ? 'A' : 'P');

    print(TIME_X, TIME_Y, "Time: ", DARKGRAY);
    cprintf("%02d:%02d:%02d %cM", t.ti_hour, t.ti_min, t.ti_sec, m);
    gotoxy(CURSOR_X, CURSOR_Y);
}

void updateDateTime()
{
    _setcursortype(_NOCURSOR);

    updateDate();
    updateTime();

    _setcursortype(_NORMALCURSOR);
}

void updateDateTimeUntilKbhit()
{
    while (!kbhit())
    {
        updateDateTime();
        delay(DELAY_MS);
    }
}

#endif // _DATETIME_UTILS_