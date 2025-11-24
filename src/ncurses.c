#include <ncurses.h>
#include "editor.h"

void init_ncurses()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
}

void shutdown_ncurses()
{
    endwin();
}
