#include <string.h>
#include <stdlib.h>
#include "editor.h"

char current_file[256];
int main(int argc, char **argv)
{
    if (argc > 1)
        strcpy(current_file, argv[1]);
    else
        strcpy(current_file, "new.txt");

    if (!strstr(current_file, "."))
        strcat(current_file, ".txt");

    load_file(current_file);

    init_ncurses();

    while (1)
    {
        editor_refresh_screen();
        handle_input();
    }

    shutdown_ncurses();
    return 0;
}
