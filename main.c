#include <gtksourceview/gtksource.h>
#include "global.h"
#include "commands.h"
#include "menu.h"
#include "tools.h"
#include "explorer.h"

int main(int argc, char * argv[]) {

    struct Editor editor;
    editor.current = NULL;
    editor.pages = NULL;

    gtk_init(NULL, NULL);

    GtkWidget * window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 840, 620);
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), &editor.current);

    GError *error = NULL;
    GdkPixbuf * icon = gdk_pixbuf_new_from_file("/usr/share/pixmaps/triton.png", &error);
    if (error != NULL) {
        printf(error->message);
        g_clear_error (&error);
    }
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    // Main view

    GtkWidget * tabs = gtk_notebook_new();
    g_signal_connect(tabs, "switch-page", G_CALLBACK(tab_selected), &editor);

    // Current working directory
    char cwd[256];
    getcwd(cwd, 256);
    char * current = getenv("OWD") ?: cwd;

    // Editor initilization
    editor.tabs = tabs;
    editor.cwd = current;
    editor.len = 0;
    editor.window = GTK_WINDOW(window);

    // Menu setup
    GtkAccelGroup * accel = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window), accel);

    GtkWidget * bar = gtk_menu_bar_new();
    init_menu(bar, accel, &editor.current);

    // Boxes
    GtkWidget * box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget * sections = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3);

    // Toolbar
    init_toolbar(sections);

    // Explorer
    init_explorer(sections, &editor);

    // Add boxes together
    gtk_box_pack_start(GTK_BOX(box), bar, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(box), sections, 1, 1, 0);
    gtk_box_pack_start(GTK_BOX(sections), tabs, 1, 1, 0);

    // Pack up app and run
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all (window);

    /*
    if (argc > 1) {
        if (getenv("OWD") != NULL) {
            strlcat(document.name, getenv("OWD"), sizeof(document.name));
            strlcat(document.name, "/", sizeof(document.name));
        }
        strlcat(document.name, argv[1], sizeof(document.name));
        if (access(document.name, F_OK) == 0) {
            open_file(document.name, &document);
            filename_to_title(&document);
        }
    }
    */

    gtk_main();

    return 0;
}
