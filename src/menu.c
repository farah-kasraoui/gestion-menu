#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	EID,
	ETYPE,
	ENOM,
	EDECHET,
	EDATE,
	ECOLUMNS
};
void ajouter(menu u){

FILE *f;
int b=0;
menu p;
f=fopen("menu.txt","a+");
if(f!=NULL)
{	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(u.id == p.id)
		b++;
	}
	if(b==0){
	fprintf(f,"%d %s %s %.2f %d %d %d\n",u.id,u.type,u.nom,u.dechet,u.d.j,u.d.m,u.d.a);
	
	fclose(f);
		}
	}
}

/* --------------------------------------------------------------- */ 

void supprimer(int id)
{
menu p;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("temp.txt","a");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(p.id != id)
			fprintf(g,"%d %s %s %.2f %d %d %d\n",p.id,p.type,p.nom,p.dechet,p.d.j,p.d.m,p.d.a);
	}
	
	fclose(f);
	fclose(g);
	
	remove("menu.txt");
	rename("temp.txt","menu.txt");
	}
}

/* ---------------------------------------------------------------------------- */ 
void modifier(menu u){
menu p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen("menu.txt","r");
g=fopen("temp.txt","a");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(u.id != p.id)
			fprintf(g,"%d %s %s %.2f %d %d %d\n",p.id,p.type,p.nom,p.dechet,p.d.j,p.d.m,p.d.a);
		else
			fprintf(g,"%d %s %s %.2f %d %d %d\n",p.id,u.type,u.nom,u.dechet,p.d.j,p.d.m,p.d.a);
	}
	
	fclose(f);
	fclose(g);
	remove("menu.txt");
	rename("temp.txt","menu.txt");
	}
}


/* ------------------------------------------------------------------------- */ 

void afficher(GtkWidget *liste){
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	int id;    
	float dechet ;
	char ide[20],type[30],nom[30],sdechet[20],date1[100];
    date d;
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);

    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Dechet",renderer,"text",EDECHET,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen("menu.txt","r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%d %s %s %f %d %d %d\n",&id,type,nom,&(dechet),&(d.j),&(d.m),&(d.a))!=EOF)
	{
			sprintf(ide,"%d",id);
			sprintf(date1,"%d/%d/%d",d.j,d.m,d.a);
			sprintf(sdechet,"%f",dechet);          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,ide,ETYPE,type,ENOM,nom,EDECHET,sdechet,EDATE,date1,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}

/* ------------------------------------------- */ 


menu recherche_menu(int id){
    menu p;
    FILE *f;
    f = fopen("menu.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
        	if(p.id == id){
       		     return p;
        	}
    	}
}
    fclose(f);
    return;
}



/* ------------------------------------------------------------------------------------- */ 
menu meuilleur_menu(date d1,date d2){
   	menu p;
   	FILE *f;
	int id;
	int liste_id[1000];
	date d;
	int n = 0;
	float min;
    f = fopen("menu.txt","r");
    while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
	d.j = p.d.j ;
	d.m = p.d.m;
	d.a = p.d.a;
	if(isMin(d,d2) && !isMin(d,d1)){
		liste_id[n]= p.id;
            	++n;
	}
    }

    fclose(f);	

	 min = recherche_menu(liste_id[0]).dechet ;
	 id = recherche_menu(liste_id[0]).id;
        for(int i = 1;i<n;i++){
		if(recherche_menu(liste_id[i]).dechet < min){
			min = recherche_menu(liste_id[i]).dechet;
			id =liste_id[i];
		}
	}
	

	return recherche_menu(id);
}
/* -------------------------------------------------------------- */ 

int isMin(date d1,date d2){
    if(d1.a < d2.a){
        return 1;
    }
    else if(d1.a == d2.a){
        if(d1.m < d2.m){
            return 1;
        }
        else if(d1.m == d2.m){
            if(d1.j > d2.j){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
