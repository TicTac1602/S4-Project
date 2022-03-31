#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>


typedef struct fct1
{
    GtkWidget * entry;
    GtkWidget * label;
    GtkWidget * encode_image;

} fct1;

void generate(GtkButton * button, gpointer data)
{
    printf("Generation du QR code \n");
    fct1 p = *( (fct1 *)data);
    GtkWidget * label = p.label;
    GtkWidget * entry = p.entry;
    GtkWidget * encode_image = p.encode_image;

    const char* text = gtk_entry_get_text(GTK_ENTRY(entry));

    printf("%s \n", text);

    gtk_label_set_text(GTK_LABEL(label), "test de label");

    gtk_image_set_from_file(GTK_IMAGE(encode_image), "out.bmp");

}


void createwindow(GtkApplication * app, gpointer data)
{

    GtkBuilder * builder = gtk_builder_new_from_file("interface.glade");
    if(builder == NULL)
    {
        exit(1);
    }

    //definiton des elements :

    GtkWidget * window = GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    
    GtkWidget * button = GTK_WIDGET(gtk_builder_get_object(builder,"button"));
    
    GtkWidget * entry = GTK_WIDGET(gtk_builder_get_object(builder,"entry"));
    
    GtkWidget * label = GTK_WIDGET(gtk_builder_get_object(builder,"label"));

    GtkWidget * encode_image = GTK_WIDGET(gtk_builder_get_object(builder,"encode_image"));
    
    

    //creation de la grille et ajout des widgets a la grille :

    fct1 * p = malloc(sizeof(fct1));
    p->entry = entry;
    p->label = label;
    p->encode_image = encode_image;

    //recuperations des signaux :

    g_signal_connect(button, "clicked", G_CALLBACK(generate), p);

    gtk_widget_show_all(window);

    gtk_main();
}

int main(int argc, char *argv[])
{

GtkApplication * app;
app = gtk_application_new("test.com", G_APPLICATION_FLAGS_NONE);
g_signal_connect(app, "activate", G_CALLBACK(createwindow), NULL);

int status = g_application_run(G_APPLICATION(app),argc, argv);

g_object_unref(app);


return status;

}