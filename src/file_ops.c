#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

void load_file(const char *filename)
{
    lines = malloc(sizeof(char*) * 1024);
    line_count = 0;

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        lines[0] = calloc(1, 512);
        line_count = 1;
        return;
    }

    char buf[512];
    while (fgets(buf, sizeof(buf), f))
    {
        buf[strcspn(buf, "\n")] = 0;
        lines[line_count] = strdup(buf);
        line_count++;
    }

    fclose(f);

    if (line_count == 0)
    {
        lines[0] = calloc(1, 512);
        line_count = 1;
    }
}

void save_file(const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for (int i = 0; i < line_count; i++)
        fprintf(f, "%s\n", lines[i]);

    fclose(f);
}
