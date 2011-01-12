#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib.h>

#ifdef WIN32 // .drectve is an win32 extension
asm (".section .drectve");
asm (".ascii \"-export:gtk_adds_text_iter_new\"");
asm (".ascii \" -export:gtk_adds_text_view_popup_menu\"");
asm (".ascii \" -export:gtk_adds_dialog_vbox\"");
asm (".ascii \" -export:gtk_adds_tree_iter_new\"");
asm (".ascii \" -export:gtk_adds_widget_mapped_p\"");
asm (".ascii \" -export:gtk_adds_widget_visible_p\"");
asm (".ascii \" -export:gtk_adds_widget_window\"");
asm (".ascii \" -export:gtk_adds_color_new\"");
asm (".ascii \" -export:gtk_adds_color_set_rgb\"");
asm (".ascii \" -export:gtk_adds_ok\"");
asm (".ascii \" -export:gtk_adds_g_thread_supported\"");
asm (".ascii \" -export:gtk_adds_widget_height\"");
asm (".ascii \" -export:gtk_adds_widget_width\"");
#endif

GdkColor *
gtk_adds_color_new ()
{
    return ((GdkColor *)malloc(sizeof(GdkColor)));
}

void
gtk_adds_color_set_rgb (GdkColor* color, guint r, guint g, guint b)
{
    color->red = r;
    color->green = g;
    color->blue = b;
}

/* You can run this one without having gtk running, to be sure the library was loaded. */
int
gtk_adds_ok ()
{
  return 1;
}

/* This macro tells us whether g_thread_init has already been called from this session
   This is important to avoid double initialization, which kills the current lisp session */

int
gtk_adds_g_thread_supported ()
{
  return g_thread_supported ();
}

/* This is to return the new allocated height/width after the user reshapes a widget */
int
gtk_adds_widget_height (GtkWidget *wid)
{
  return wid->allocation.height;
}

int
gtk_adds_widget_width (GtkWidget *wid)
{
  return wid->allocation.width;
}

