#include "editor.h"
#include <stdlib.h>

void handle_input()
{
    int c = getch();

    switch (c)
    {
        case 17: endwin(); exit(0); break;  
        case 19: save_file(current_file); break; 

        case KEY_LEFT:
            if (cursor_x > 0) cursor_x--;
            break;

        case KEY_RIGHT:
            cursor_x++;
            break;

        case KEY_UP:
            if (cursor_y > 0)
                cursor_y--;
            if (cursor_y < top_line)   
                top_line--;
            break;

        case KEY_DOWN:
            if (cursor_y < line_count - 1)
                cursor_y++;
            if (cursor_y >= top_line + LINES) 
                top_line++;
            break;

        case KEY_BACKSPACE:
        case 127:  
            editor_delete_char();
            break;

        case KEY_DC:    
            cursor_x++;
            editor_delete_char();
            break;

        case 10: editor_newline(); break; 

        default:
            if (c >= 32 && c <= 126)
                editor_insert_char(c);
    }
}
