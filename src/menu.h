#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct
{
    int j;
    int m;
    int a;
}date;

typedef struct
{
    int id;
    char type[20];
    char nom[20];
    float dechet;
    date d;
}menu;

void ajouter(menu u);
void supprimer(int id);
void modifier(menu u);
void afficher(GtkWidget *liste);
int isMin(date d1,date d2);
menu meuilleur_menu(date d1,date d2);
menu recherche_menu(int id);
