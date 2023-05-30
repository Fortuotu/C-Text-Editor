
typedef struct
{
    char *file_data;

    u_int32_t cursor_x, cursor_y;
} editor_t;

void editor_init(editor_t *editor);

void editor_refresh_display(editor_t* editor);

void editor_load_file(editor_t *editor, const char *file_path);
void editor_save_file(editor_t *editor);

void editor_move_cursor(editor_t *editor, int32_t key);
void editor_handle_input(editor_t *editor);
