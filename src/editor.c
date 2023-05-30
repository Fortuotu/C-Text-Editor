#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/editor.h"

void editor_init(editor_t *editor)
{
    editor->cursor_x = 0;
    editor->cursor_y = 0;
}

void editor_refresh_display(editor_t *editor)
{
    move(editor->cursor_y, editor->cursor_x);
}

void editor_load_file(editor_t *editor, const char *file_path)
{
    FILE *file = fopen(file_path, "r");

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    editor->file_data = malloc(file_size + 1);
    fread(editor->file_data, file_size, 1, file);
    fclose(file);

    printw("%s", editor->file_data);
    // editor->file_data[fsize] = '\0';
}

void editor_save_file(editor_t *editor)
{
    //int32_t max_x, max_y;
    //char buffer[][max_x]

}

void editor_move_cursor(editor_t *editor, int32_t input_key)
{

    int32_t max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    //printw("max_x: %d\nmax_y: %d", max_x, max_y);

    switch (input_key)
    {
    case KEY_UP:
        if (editor->cursor_y != 0)
            editor->cursor_y--;
        break;
    case KEY_DOWN:
        if (editor->cursor_y != max_y)
            editor->cursor_y++;
        break;
    case KEY_LEFT:
        editor->cursor_x--;
        break;
    case KEY_RIGHT:
        editor->cursor_x++;
        break;
    }
}

void editor_handle_input(editor_t *editor)
{
    int32_t input_key = getch();
    
    switch (input_key)
    {
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
        editor_move_cursor(editor, input_key);
        break;

    case 0x7F:
        mvdelch(editor->cursor_y, editor->cursor_x - 1);
        editor_move_cursor(editor, KEY_LEFT);
        break;

    default:
        addch(input_key);
        editor_move_cursor(editor, KEY_RIGHT);
        break;
    }
}
