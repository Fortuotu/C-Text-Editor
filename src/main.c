#include <ncurses.h>

#include "../include/editor.h"

int main(int argc, char **argv)
{
	initscr();

	raw();
	keypad(stdscr, TRUE);
	noecho();

	editor_t editor;

	editor_init(&editor);

	editor_load_file(&editor, argv[1]);

	while (1) {
		editor_refresh_display(&editor);
		editor_handle_input(&editor);
	}

	return 0;
}
