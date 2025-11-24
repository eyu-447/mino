#include <stdlib.h>
#include <string.h>
#include "editor.h"

char **lines = NULL;
int line_count = 0;
int top_line = 0;  

int cursor_x = 0;
int cursor_y = 0;

void editor_insert_char(char c)
{
    int len = strlen(lines[cursor_y]);

    if (cursor_x > len)
    {
        lines[cursor_y] = realloc(lines[cursor_y], cursor_x + 2);

        for (int i = len; i < cursor_x; i++)
            lines[cursor_y][i] = ' ';

        lines[cursor_y][cursor_x] = 0;
        len = cursor_x;
    }

    lines[cursor_y] = realloc(lines[cursor_y], len + 2);

    for (int i = len; i >= cursor_x; i--)
        lines[cursor_y][i + 1] = lines[cursor_y][i];

    lines[cursor_y][cursor_x] = c;
    cursor_x++;
}

void editor_delete_char()
{
    int len = strlen(lines[cursor_y]);

    if (cursor_x == 0 && cursor_y == 0)
        return;

    if (cursor_x > 0)
    {
        for (int i = cursor_x - 1; i < len; i++)
            lines[cursor_y][i] = lines[cursor_y][i + 1];

        cursor_x--;
        return;
    }

    if (cursor_x == 0 && cursor_y > 0)
    {
        int prev_len = strlen(lines[cursor_y - 1]);
        lines[cursor_y - 1] = realloc(lines[cursor_y - 1], prev_len + len + 1);

        strcat(lines[cursor_y - 1], lines[cursor_y]);

        free(lines[cursor_y]);

        for (int i = cursor_y; i < line_count - 1; i++)
            lines[i] = lines[i + 1];

        line_count--;
        cursor_y--;
        cursor_x = prev_len;
    }
}


void editor_newline()
{
    line_count++;
    lines = realloc(lines, sizeof(char*) * line_count);
    for (int i = line_count - 1; i > cursor_y + 1; i--)
        lines[i] = lines[i-1];

    lines[cursor_y + 1] = calloc(1, 512);

    cursor_y++;
    cursor_x = 0;
}
