void open_command(GtkWidget * self, struct Document ** document);

void open_folder_command(GtkWidget * self, struct Editor * editor);

void clear_editor(struct Editor * editor);

void new_command(void);

void new_file_command(GtkWidget * self, struct Editor * editor);

void new_folder_command(GtkWidget * self, struct Editor * editor);

void save_command(GtkWidget * self, struct Document ** document);

void save_as_command(GtkWidget * self, struct Document ** document);

void print_command(GtkWidget * self, struct Document ** document);

void print_preview_command(GtkWidget * self, struct Document ** document);

void close_tab_command(GtkWidget * self, struct Editor * editor);

void exit_command(GtkWidget * self, struct Editor * editor);

gboolean delete_event(GtkWidget* self, GdkEvent* event, struct Editor * editor);

void undo_command(GtkWidget * self, struct Document ** document);

void redo_command(GtkWidget * self, struct Document ** document);

void cut_command(GtkWidget * self, struct Document ** document);

void copy_command(GtkWidget * self, struct Document ** document);

void paste_command(GtkWidget * self, struct Document ** document);

void delete_command(GtkWidget * self, struct Document ** document);

void select_all_command(GtkWidget * self, struct Document ** document);

void search_command(GtkWidget * self, struct Document ** document);

void search_next_command(GtkWidget * self, struct Document ** document);

void replace_command(GtkWidget * self, struct Document ** document);

void go_to_command(GtkWidget * self, struct Document ** document);

void theme_command(GtkWidget * self, struct Editor * document);

void font_command(GtkWidget * self, struct Document ** document);

void wrap_command(GtkWidget * self, struct Document ** document);

void spaces_command(GtkWidget * self, struct Document ** document);

void about_command(GtkWidget * self, struct Editor * editor);