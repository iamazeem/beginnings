#include <stdio.h>
#include <conio.h>
#include <constrea.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <dir.h>
#include <dirent.h>

// Macros Replacements
#define STR_LEN 16
#define ARROW   23
#define ESC     27
#define ENTER   13

// Window Areas for Interface
constream cMsg, cBox, cs1, cs2;
constream rMsg, rScr, rs;
constream timeBox, dateBox, cmdBox;
constream result, cmd, status;

// Function Prototypes
void showInterface();
void showCommands();
char getKey();
void printDate();
void printTime();
void printArrows(int n);
void printCWD();
void printDirectoryListing();
void printAvailableSpace();

int main()
{
    showInterface();
    showCommands();

    char cmdStr[STR_LEN] = {0};
    int col = 0;
    int isExit = 0;

    while (!isExit)
    {
        char key = getKey();
        switch (key)
        {
        case ENTER:
            cmdStr[col] = '\0';

            if (strcmpi(cmdStr, "help") == 0)
            {
                showCommands();
                cmd.clrscr();
            }
            else if (strcmpi(cmdStr, "exit") == 0)
            {
                isExit = 1;
            }
            else if (strcmpi(cmdStr, "cls") == 0)
            {
                result.clrscr();
                cmd.clrscr();
            }
            else if (strcmpi(cmdStr, "dir") == 0)
            {
                printDirectoryListing();
                cmd.clrscr();
            }
            else if (strcmpi(cmdStr, "cd..") == 0)
            {
                chdir("..");
                cmd.clrscr();
            }
            else if (strcmpi(cmdStr, "cd...") == 0)
            {
                chdir("...");
                cmd.clrscr();
            }
            else if (strcmpi(cmdStr, "cd\\") == 0)
            {
                chdir("\\");
                cmd.clrscr();
            }
            else
            {
                result << "Invalid command! [" << cmdStr << "]\n";
                cmd.clrscr();
            }

			cmdStr[0] = '\0';
            col = 0;
            break;

        case ESC:
			cmd.clrscr();
            cmdStr[0] = '\0';
            col = 0;
            break;

        default:
            if (col < STR_LEN && isprint(key))
            {
				cmd << key;
                cmdStr[col] = key;
                ++col;
            }
        }
    }

    printf("Exit...\n\n");
    clrscr();
    return 0;
}

// Function Definitions

void showInterface()
{
    textmode(C80);
    textcolor(WHITE);
    textbackground(BLUE);
    clrscr();

    gotoxy(32, 2); printArrows(17);
    gotoxy(26, 8); printArrows(29);
    
    cMsg.window(32, 1, 48, 1);
    _setcursortype(_NOCURSOR);
    textbackground(RED);
    textcolor(BLUE);
    clrscr();
    printf("   Command Box");

    cs1.window(1, 4, 25, 6);
    textbackground(BLACK); clrscr();
    
    cs1.window(55, 4, 80, 6);
    textbackground(BLACK);
    clrscr();
    
    cBox.window(2, 3, 79, 5);
    textbackground(LIGHTGREEN);
    clrscr();
    
    cmdBox.window(4, 4, 13, 4);
    textbackground(BLUE);
    textcolor(WHITE + BLINK);
    clrscr();
    cprintf(" >>");    
    
    cmd.window(14, 4, 77, 4);
    textbackground(BLUE);
    textcolor(WHITE);
    clrscr();
    
    rMsg.window(26, 7, 54, 7);
    textbackground(RED);
    textcolor(BLUE);
    clrscr();
    cprintf("        Result Screen");
    
    rs.window(1, 11, 80, 25);
    textbackground(BLACK);
    clrscr();
    
    rScr.window(3, 9, 78, 24);
    textbackground(LIGHTGREEN);
    clrscr();
    
    status.window(5, 10, 76, 10);
    textbackground(BLACK);
    textcolor(LIGHTGRAY);
    clrscr();
    
    dateBox.window(3, 8, 20, 8);
    textbackground(WHITE);
    textcolor(DARKGRAY);
    clrscr();
    printDate();

    timeBox.window(60, 8, 78, 8);
    textbackground(WHITE);
    textcolor(DARKGRAY);
    clrscr();
    
    result.window(5, 12, 76, 23);
    textbackground(BLUE);
    highvideo();
    textcolor(CYAN);
    clrscr();
}

void showCommands()
{
    result.clrscr();
    result << "Commands:\n"
           << "\n  help     show all commands"
           << "\n  dir      show the contents of current directory"
           << "\n  exit     close and leave"
           << "\n  cd..     leave one directory"
           << "\n  cd..     leave two directories"
           << "\n  cd\\      leave all directories\n";
}

char getKey()
{
    printCWD();
    
    while (!kbhit())
    {
        printTime();
        delay(100);
    }

    char key = getch();
    if (key == 0) // extended key
    {
        key = getch();
        return key;
    }

    return key;
}

void printDate()
{
    static struct date d = {0};
    getdate(&d);
    printf(" Date: %d-%d-%d", d.da_day, d.da_mon, d.da_year);
}

void printTime()
{
    static struct time t = {0};
    gettime(&t);

    if (t.ti_hour > 12)
    {
        t.ti_hour -= 12;
    } 

    timeBox.clrscr();
    _setcursortype(_NOCURSOR);

    char m = (t.ti_hour >= 12 ? 'P' : 'A');
    printf(" Time: %2d:%02d:%02d %cM", t.ti_hour, t.ti_min, t.ti_sec, m);
    
    _setcursortype(_NOCURSOR);
}

void printArrows(int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%c", ARROW);
    }
}

void printCWD()
{
    char path[MAXPATH] = {0};
    getcwd(path, MAXPATH);

    status.clrscr();
    _setcursortype(_NOCURSOR);
    textcolor(YELLOW);
    cprintf(" Current drive and working directory: %s", path);
    _setcursortype(_NOCURSOR);
}

void printDirectoryListing()
{
	unsigned long nfiles = 0;
	unsigned long ndir = 0;
	unsigned long totalsize = 0;
	int row = 1;

	result.clrscr();

	struct find_t ff = {0};
	int done = _dos_findfirst("*.*", FA_DIREC, &ff);
    while (!done)
    {
		if (ff.attrib & _A_SUBDIR)
        {
			result << ff.name;
            gotoxy(9, row);
			result << "      <DIR>       " << ff.name << '\n';
            ++ndir;
            ++row;
        }
        else
        {
            struct fcb f = {0};
			parsfnm(ff.name, &f, 1);
            result << f.fcb_name;
            gotoxy(9, row);
			result << "   " << f.fcb_ext << setw(12) << ff.size << "  " << ff.name << '\n';
            ++nfiles;
            ++row;
        }

        if (row == 12)
        {
            row = 1;
            result << "--- Press any key to continue or ESC to abort ---";
            _setcursortype(_NOCURSOR);

            if (getch() == ESC)
            {
                result << " [ABORTED]\n";
                return;
            }

            result.clrscr();
        }

		totalsize += ff.size;
        
		done = _dos_findnext(&ff);
    }

    result << '\n' << setw(9) << nfiles << " file(s)" << setw(18) << totalsize << " bytes\n";
    result << setw(9) << ndir << " dir(s)";

    printAvailableSpace();

    _setcursortype(_NORMALCURSOR);
}

void printAvailableSpace()
{
    int drive = getdisk();

    struct dfree free = {0};
    getdfree(drive + 1, &free);

    unsigned long avail = (long) free.df_avail * (long) free.df_bsec * (long) free.df_sclus;
    result << setw(19) << avail << " bytes free\n\n";
}
