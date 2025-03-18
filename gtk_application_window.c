#include <gtk/gtk.h>

static void click_cb(GtkButton *button, gpointer user_data) {
    g_print("Clicked -> %s\n", (char *)user_data);
}

static void click_quit(GtkButton *button, GtkApplicationWindow *window) {
  g_print("Saindo...\n");
  gtk_window_destroy (GTK_WINDOW (window));
}

static void activate(GApplication *app, gpointer *user_data) {

  GtkWidget *window;
  GtkWidget *label1;
  GtkWidget *separator1;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;

  GtkBuilder *builder;
  GtkCssProvider *provider;

  GdkDisplay *display;

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new_from_file("window.ui");

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
  gtk_window_set_application(GTK_WINDOW(window), GTK_APPLICATION(app));
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

  /* Alterar cor da fonte com CSS */
  provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, "style.css");

  /* Aplica o provedor de CSS à tela */
  display = gdk_display_get_default();
  gtk_style_context_add_provider_for_display(
      display, GTK_STYLE_PROVIDER (provider),
      GTK_STYLE_PROVIDER_PRIORITY_USER);

  /* Cria um GtkSeparator */
  separator1 = GTK_WIDGET(gtk_builder_get_object(builder, "separator1"));
  gtk_widget_add_css_class(GTK_WIDGET(separator1), "separator");

  /* Cria um GtkLabel */
  label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
  gtk_label_set_text(GTK_LABEL(label1), "Novo label...");

   /* Cria um GtkButton */
  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
  g_signal_connect(button1, "clicked", G_CALLBACK(click_cb), "Button 1");
  gtk_widget_add_css_class(GTK_WIDGET(button1), "bt");

  button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
  g_signal_connect(button2, "clicked", G_CALLBACK(click_cb), "Button 2");
  gtk_widget_add_css_class(GTK_WIDGET(button2), "bt");

  button3 = GTK_WIDGET(gtk_builder_get_object (builder, "quit"));
  g_signal_connect(button3, "clicked", G_CALLBACK(click_quit), window);
  gtk_widget_add_css_class(GTK_WIDGET(button3), "bt_quit");

  g_object_unref(builder);

  gtk_window_present(GTK_WINDOW (window));
}

int main (int argc, char *argv[]) {

  GtkApplication *app;
  int status;

  /* Create a GtkApplication instance. */
  app = gtk_application_new("com.alanpasi.gtk_application_window",
                             G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  /* Run the application. */
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
