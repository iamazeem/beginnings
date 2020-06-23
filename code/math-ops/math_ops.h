#ifndef _MATH_OPS_
#define _MATH_OPS_

#include "menu.h"
#include "arit_ops.h"
#include "trig_ops.h"
#include "util_ops.h"

struct MathOps
{
    static void start();
};

void MathOps::start()
{
    const MenuItem items[] =
    {
        { 22,  5, "нннлл  MATHEMATICAL OPERATIONS  ллооо", NO_OP },
        { 21,  9, " Arithmetic Operations ", Arithmetic::menu },
        { 21, 11, " Trigonometric Operations ", Trigonometric::menu },
        { 21, 13, " Utilities ", Utils::menu },
        { 21, 15, " EXIT (ESC) ", NO_OP }
    };

    const size_t nItems = sizeof(items) / sizeof(items[0]);

    Menu menu(items, nItems);

    drawBismillah();
    drawStartupScreen();

    do
    {
        menu.start();

    } while (!confirmExit());

    bye();
}

#endif // _MATH_OPS_
