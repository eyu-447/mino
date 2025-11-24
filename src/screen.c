#include "editor.h"

void editor_refresh_screen()
{
    clear();
    int max_lines = LINES;

    for (int i = 0; i < max_lines && (top_line + i) < line_count; i++)
    {
        mvprintw(i, 4, "%s", lines[top_line + i]);
        mvprintw(i, 0, "%d |", top_line + i + 1);
    }

    move(cursor_y - top_line, cursor_x + 4);
    refresh();
}
