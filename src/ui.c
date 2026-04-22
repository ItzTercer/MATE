// Funciones de interfaz de usuario: configuración de botones y ventana. :3

#include <gtk/gtk.h>
#include "ui.h"

//Función: qué ocurre cuando se presiona algún botón.
static void
on_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkWidget *entry = GTK_WIDGET(user_data);
    const char *txt = gtk_button_get_label(button);

    if (g_strcmp0(txt, "+") == 0) { //De momento solo avisa que hacen, en un futuro tal vez podría usar struct por si llegamos a hacer una calculador más complicada.
        g_print("Operador suma\n"); 
    } else if (g_strcmp0(txt, "-") == 0) {
        g_print("Operador resta\n");
    } else if (g_strcmp0(txt, "*") == 0) {
        g_print("Operador multiplicación\n");
    } else if (g_strcmp0(txt, "/") == 0) {
        g_print("Operador división\n");
    } else if (g_strcmp0(txt, "=") == 0) {
        g_print("Calcular resultado\n");
    } else if (g_strcmp0(txt, "C") == 0) { //C borra lo que esta escrito en la pantalla de entrada.
        gtk_editable_set_text(GTK_EDITABLE(entry), "");
    } else {
        const char *actual = gtk_editable_get_text(GTK_EDITABLE(entry));
        char nuevo[256];

        g_snprintf(nuevo, sizeof(nuevo), "%s%s", actual, txt);
        gtk_editable_set_text(GTK_EDITABLE(entry), nuevo);
    }
}

void
build_ui(GtkApplication *app)
{
    GtkWidget *win;
    GtkWidget *box1;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *grid;

    const char *labels[4][4] = { //Matriz para los botones
    {"7", "8", "9", "/"},
    {"4", "5", "6", "*"},
    {"1", "2", "3", "-"},
    {"C", "0", "=", "+"} };

    win = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(win), "CountPlay");
    gtk_window_set_default_size(GTK_WINDOW(win), 400, 300);

    box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box1, 20);
    gtk_widget_set_margin_bottom(box1, 20);
    gtk_widget_set_margin_start(box1, 20);
    gtk_widget_set_margin_end(box1, 20);

    gtk_window_set_child(GTK_WINDOW(win), box1);
    
    label = gtk_label_new("Calculadora");
    entry = gtk_entry_new();

    gtk_box_append(GTK_BOX(box1), label);
    gtk_box_append(GTK_BOX(box1), entry);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 8);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    gtk_box_append(GTK_BOX(box1), grid);

    for (int fila = 0; fila < 4; fila++) { //Agrego los botones.
        for (int col = 0; col < 4; col++) {
            GtkWidget *btn = gtk_button_new_with_label(labels[fila][col]);
            gtk_grid_attach(GTK_GRID(grid), btn, col, fila, 1, 1);

            g_signal_connect(btn, "clicked", G_CALLBACK(on_button_clicked),entry);
        }
    }

    gtk_window_present(GTK_WINDOW(win));
}
