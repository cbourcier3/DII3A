/*  hello world for gtk with cairo support, by Øvyind Kolås
commandes pour installer GTK :
apt-get install libgtk2.0-dev
apt-get install libcairo2-dev
 */

#include <gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void paint (GtkWidget *widget, GdkEventExpose *eev, gpointer        data);
int signe(int one, int other);

gint
main (gint    argc, gchar **argv)
{
  GtkWidget *window;
  GtkWidget *canvas;

  gint Largeur;
  gint Hauteur;
  gtk_init (&argc, &argv);

  window   = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_maximize(GTK_WINDOW(window));
  gtk_window_get_size(GTK_WINDOW(window), &Largeur, &Hauteur);
  g_signal_connect (G_OBJECT (window), "delete-event", G_CALLBACK (gtk_main_quit), NULL);

  canvas = gtk_drawing_area_new ();
  gtk_widget_set_size_request (canvas, Largeur, Hauteur-100);
  g_signal_connect (G_OBJECT (canvas), "expose-event",G_CALLBACK (paint), NULL );

  gtk_container_add (GTK_CONTAINER (window), canvas);

  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}

static void
paint (GtkWidget      *widget, GdkEventExpose *eev, gpointer data)
{
  gint width, height;
  int actualx=0;
  int actualy=0;
  cairo_t *cr;
  width  = widget->allocation.width;
  height = widget->allocation.height;
  cr = gdk_cairo_create (widget->window);

  int *axex;
  int *axey;
  axex = malloc(20*sizeof(int));
  axey = malloc(20*sizeof(int));
    axex[0] = 68;
    axey[0]= 0;
    axex[1] = 82;
    axey[1] = 3;
    axex[2] = 99;
    axey[2] = 5;
    axex[3] = 122;
    axey[3] = 9;
    axex[4] = 140;
    axey[4] = 13;
    axex[5] = 145;
    axey[5] = 13;
    axex[6] = 167;
    axey[6] = 12; 
    axex[7] = 185;
    axey[7] = 8;
    axex[8] = 200;
    axey[8] = 4;
    axex[9]= 204;
    axey[9]= 1;
    axex[10] =212;
    axey[10] = -2;
    axex[11] = 227;
    axey[11]= -10;
    axex[12] = 234;
    axey[12] = -12;
    axex[13] = 244;
    axey[13] = -16;
    axex[14] = 272;
    axey[14] = -22;
    axex[15] = 297;
    axey[15] = -29;
    axex[16] = 311;
    axey[16] = -32;
    axex[17] = 338;
    axey[17] = -34;
    axex[18]= 355;
    axey[18]= -35;
    axex[19]= 369;
    axey[19] = -38;
    axex[20] = 387;
    axey[20] =  -42;
    cairo_set_source_rgb (cr, 1,1,1);
    cairo_paint (cr);

    cairo_set_source_rgb (cr, 0,0,1);
    actualx=68;
    actualy=0;
     cairo_set_source_rgba(cr, 0, 0, 0, 1);

  cairo_set_line_width(cr, 1);

  cairo_move_to (cr, 10,height/4);


    for (int i=1;i<20;i++)
    {

      switch (signe(actualx,axex[i]))
      {
        case 1:
          actualx = axex[i]-actualx;
          break;
        case 2:
          actualx = axex[i]-actualx;
          break;
        case 3:
          actualx = -actualx - axex[i];      
           break;
        case 4:
          actualx = -actualx+axex[i];
          break;
      }

      switch (signe(actualy,axey[i]))
      {
        case 1:
          actualy = axey[i]-actualy;
          break;
        case 2:
          actualy = axey[i]-actualy;
          break;
        case 3:
          actualy = -actualy - axey[i];      
           break;
        case 4:
          actualy = -actualy+axey[i];
          break;
      }

     
      
      cairo_rel_line_to(cr,actualx, actualy);
  

    }
    cairo_stroke(cr);
    //cairo_set_source_rgb (cr, 0,1,1);
    actualx=68;
    actualy=0;
    cairo_move_to (cr, 10,height/0.75);

    for (int y=1;y<20;y++)
    {

      switch (signe(actualx,axex[y]))
      {
        case 1:
          actualx = axex[y]-actualx;
          break;
        case 2:
          actualx = axex[y]-actualx;
          break;
        case 3:
          actualx = -actualx - axex[y];      
           break;
        case 4:
          actualx = -actualx+axex[y];
          break;
      }

      switch (signe(actualy,axey[y]))
      {
        case 1:
          actualy = axey[y]-actualy;
          break;
        case 2:
          actualy = axey[y]-actualy;
          break;
        case 3:
          actualy = -actualy - axey[y];      
           break;
        case 4:
          actualy = -actualy+axey[y];
          break;
      }
    
      
      cairo_rel_line_to(cr,actualx, actualy);
    }
    cairo_stroke(cr);


  
  }
int signe(int one, int other)
// Retourne 1 si one et other > 0, 2 si one et other <0, 3 si one >0 et other <0, et 4 si one <0 et other >0
{
  int test;
  if (one >=0 && other >=0)
      test =1;
  if (one < 0 && other < 0)
      test = 2;
  if (one >= 0 && other <0)
      test = 3;
  if (one < 0 && other >= 0)
      test = 4;

  return test;
}