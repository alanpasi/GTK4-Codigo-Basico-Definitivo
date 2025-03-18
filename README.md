# Código básico definitivo!!!
by Alanpasi (13/03/2025)

Reference:\
  https://github.com/ToshioCP/Gtk4-tutorial\
  by ToshioCP

gtk_application_new() (Cosntructor)\
  https://docs.gtk.org/gtk4/ctor.Application.new.html

g_signal_connect() - (Function Macro)\
  https://docs.gtk.org/gobject/func.signal_connect.html

gtk_builder_new_from_file() - (Constructor)\
  https://docs.gtk.org/gtk4/ctor.Builder.new_from_file.html


## GtkApplicationWindow
GtkApplicationWindow is a child object of GtkWindow. It has some extra feature for better integration with GtkApplication. It is recommended to use it as the top-level window of the application instead of GtkWindow.

When you create GtkApplicationWindow, you need to give GtkApplication instance as an argument. Then it automatically connect these two instances. So you don't need to call gtk_window_set_application any more.

The function 'gtk_window_set_child(GTK_WINDOW(window), label)' makes the label 'label' a child widget of the window 'window'. Be careful. A child widget is different from a child object. Objects have parent-child relationships and widgets also have parent-child relationships. But these two relationships are totally different. Don't be confused. In the program, 'label' is a child widget of 'window'.

The window 'window' doesn't have any parents. We call such a window top-level window. An application can have more than one top-level windows.
