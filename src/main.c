#include <gtk/gtk.h>
#include "ui.h"

// Archivo principal: inicia la aplicación, !!es necesario instalar GTK4:
//       sudo apt install libgtk-4-dev pkg-config
//Para compilar:
//       gcc $(pkg-config --cflags gtk4) main.c ui.c -o main $(pkg-config --libs gtk4)
//Puede que en vs studio code salga error en el "#include <gtk/gtk.h>", si es que gtk4
//esta correctamente instalado y además la app compila bien: se puede ignorar el error.

static void
app_activate(GApplication *app, gpointer user_data)
{
    build_ui(GTK_APPLICATION(app));
}

int
main(int argc, char **argv)
{
    GtkApplication *app;
    int stat;

    app = gtk_application_new("cl.countplay", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
    stat = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return stat;
}
