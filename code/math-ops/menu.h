#ifndef _MENU_
#define _MENU_

#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "globals.h"
#include "io_utils.h"
#include "datetime.h"
#include "ui.h"

#define DEFAULT_MENU_CHOICE     'A'     // default: first menu item
#define DEFAULT_MENU_DIRECTION  0       // no direction at start i.e. first item
#define MAX_MENU_ITEMS          (8+1)   // maximum number of menu items + heading
#define DEFAULT_HEADING_INDEX   0       // ZERO index is reserved for heading

typedef void (*callback)(void);

static const callback NO_OP = NULL;

struct MenuItem
{
    int             x;                  // column
    int             y;                  // row
    const char*     label;              // text to show
    callback        cb;                 // callback against item
};

class Menu
{
public:
    Menu(const MenuItem* items_, const size_t nItems_);

    void start();

private:
    const MenuItem* items;              // list of menu items
    size_t          nItems;             // number of menu items
    char            choice;             // selected menu item

    void setDirection(const int direction);
    bool isValidChoice(const char menuChoice) const;
    void setCurrentChoice(const char menuChoice);
    int getCurrentItemIndex() const;
    bool isLastItemSelected() const;

    void draw() const;
    void runCurrentChoice() const;
};

Menu::Menu(const MenuItem* items_, const size_t nItems_)
    :
    items(items_),
    nItems(nItems_),
    choice(DEFAULT_MENU_CHOICE)
{
    assert(items != NULL);
    assert(nItems > 0 && nItems <= MAX_MENU_ITEMS);
}

void Menu::start()
{
    setDirection(DEFAULT_MENU_DIRECTION);
    drawBorder();

    bool isExit = false;
    while (!isExit)
    {
        draw();

        updateDateTimeUntilKbhit();

        const char key = getch();
        if (key == EXTENDED)
        {
            const char direction = getch();
            if (direction == UP || direction == DOWN)
            {
                setDirection(direction);
            }
        }
        else if (isalpha(key))
        {
            setCurrentChoice(key);
        }
        else if (key == ENTER)
        {
            if (isLastItemSelected())
            {
                isExit = true;
            }
            else
            {
                runCurrentChoice();
            }
        }
        else if (key == ESC)
        {
            isExit = true;
        }
    }

    drawBorder();
}

void Menu::setDirection(const int direction)
{
    const char op0 = DEFAULT_MENU_CHOICE;
    const char opN = op0 + nItems - 2;

    switch (direction)
    {
    case DEFAULT_MENU_DIRECTION:
        choice = DEFAULT_MENU_CHOICE;
        break;

    case DOWN:
        choice = (choice < opN ? choice + 1 : op0);
        break;

    case UP:
        choice = (choice > op0 ? choice - 1 : opN);
        break;

    default:
        beep();
        return;
    }
}

bool Menu::isValidChoice(const char menuChoice) const
{
    const char op0 = DEFAULT_MENU_CHOICE;
    const char opN = op0 + nItems - 2;
    return (menuChoice >= op0 && menuChoice <= opN) ? true : false;
}

void Menu::setCurrentChoice(const char menuChoice)
{
    const char newChoice = toupper(menuChoice);
    if (isValidChoice(newChoice))
    {
        choice = newChoice;
    }
}

int Menu::getCurrentItemIndex() const
{
    return (choice - DEFAULT_MENU_CHOICE + 1);
}

bool Menu::isLastItemSelected() const
{
    const int lastItemIndex = nItems - 1;
    return (getCurrentItemIndex() == lastItemIndex ? true : false);
}

void Menu::draw() const
{
    assert(isValidChoice(choice) == true);

    _setcursortype(_NOCURSOR);

    for (int i = 0; i < nItems; ++i)
    {
        const MenuItem& item = items[i];

        if (i == DEFAULT_HEADING_INDEX)
        {
            print(item.x, item.y, item.label, YELLOW);
        }
        else
        {
            const char option = DEFAULT_MENU_CHOICE + i - 1;
            print(item.x, item.y, option, LIGHTRED); print(") ", RED); print(item.label, BROWN);
        }
    }

    const int index = getCurrentItemIndex();
    const MenuItem& item = items[index];
    const char option = DEFAULT_MENU_CHOICE + index - 1;
    print(item.x, item.y, option, LIGHTRED); print(") ", RED); print(item.label, DARKGRAY, LIGHTGRAY, BLINK);

    gotoxy(48, 18); cprintf("%c\b", choice);
    _setcursortype(_NORMALCURSOR);
}

void Menu::runCurrentChoice() const
{
    const int index = getCurrentItemIndex();
    const MenuItem& item = items[index];
    if (item.cb != NULL)
    {
        item.cb();
    }
}

#endif // _MENU_
