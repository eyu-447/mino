#ifndef EDITOR_H
#define EDITOR_H

#include <ncurses.h>
extern int top_line;
extern char **lines;
extern int line_count;
extern char current_file[256];
extern int cursor_x;
extern int cursor_y;

// file_ops.c
void load_file(const char *filename);
void save_file(const char *filename);

// input.c
void handle_input();

// screen.c
void editor_refresh_screen();

// buffer.c
void editor_insert_char(char c);
void editor_newline();
void editor_delete_char();

// ncurses.c
void init_ncurses();
void shutdown_ncurses();

#endif
