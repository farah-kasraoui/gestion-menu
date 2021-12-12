#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"

int x = 1;
/* -------------------- NAVIGATION ----------------- */ 

void
on_toafficherFarah_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_liste_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_ToajoutFarah_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_ajout_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_tomodfiFarah_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_modifier_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_toSupprimerFarah_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_supprimer_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}
void
on_supprimer_farah_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
		char id[20],message[200];
		int ident;
		GtkWidget *input,*output; 
		input = lookup_widget(objet,"id_supp_farah");
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
		ident = atoi(id);
		
		output = lookup_widget(objet,"outputDel");
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
		supprimer(ident);
			
}

void
on_meuilleurMenuFarah_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_meilleur_menu();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);

		
}

/* ------------------------------------------------------------- */ 

void
on_retour_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"ajout_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_Retour_list_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"liste_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_retourModif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"modifier_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_retour_supp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"supprimer_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


 
void
on_ajout_farah_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *aj1, *aj2, *aj3, *a, *b, *c,*d,*month,*y,*output;
	
	char message[200];

	char id[20];
	menu m,p;
	aj1=lookup_widget(objet,"id_farah");
	aj2=lookup_widget(objet,"nomMenuFarah");
	aj3=lookup_widget(objet,"dechetFarah");

	d = lookup_widget(objet,"spinJ");
	month = lookup_widget(objet,"spinM");
	y = lookup_widget(objet,"spinA");

	output = lookup_widget(objet,"outputAdd");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(aj1)));
	m.id = atoi(id);
	strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(aj2)));
	m.dechet=atof(gtk_entry_get_text(GTK_ENTRY(aj3)));


	m.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d));
	m.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	m.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(y));


	if(x==1){
		strcpy(m.type,"petit_dejeuner");	
	}
	else if(x == 2){
		strcpy(m.type,"dejeuner");
	}
	else{
		strcpy(m.type,"diner");
	}

	sprintf(message,"Votre ajout a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
	ajouter(m);
	
	
}

void
on_radio_p_dej_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
			x=1;
		}
}


void
on_radio_dej_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_radio_d_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=3;
	}
}


void
on_valider_farah_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *mod1, *mod2, *mod3, *mod4,*output;
	menu p;
	
	char id[20],message[200];
	FILE *f;
	int a = 0,ident;
	mod1=lookup_widget(objet,"id_mod_farah");
	mod2=lookup_widget(objet,"dechet_mod_farah");
	mod3=lookup_widget(objet,"nom_mod_farah");
	mod4=lookup_widget(objet,"comboboxtype_farah");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
	ident = atoi(id);


	f = fopen("menu.txt","r");
	if(f!=NULL){

	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
		{
			if(p.id == ident){
				a=1;
				break;
		         }
		}
	fclose(f);
	}
	
	
	p.dechet = atof(gtk_entry_get_text(GTK_ENTRY(mod2)));

	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mod4)));
	
	output = lookup_widget(objet,"outputEdit");
	sprintf(message,"Votre modification a été effectué avec succés !");
	gtk_label_set_text(GTK_LABEL(output),message);
	modifier(p);

}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mod1, *mod2, *mod3,*mod4;
	menu p;
	int a=0;
	char ch[20], id[50],nom[50];
	char dechet[50];
	FILE *f;
	int ident ; 
	mod1=lookup_widget(objet,"id_mod_farah");
	mod2=lookup_widget(objet,"dechet_mod_farah");
	mod3=lookup_widget(objet,"nom_mod_farah");
	mod4=lookup_widget(objet,"comboboxtype_farah");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
	ident = atoi(id);
	
	f = fopen("menu.txt","r");
	if(f!=NULL){

	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
		{
			if(p.id == ident){
				a=1;
				break;
		         }
		}
	fclose(f);
	}
	if(a==1){
		
		sprintf(ch,"%f",p.dechet);		
		gtk_entry_set_text(GTK_ENTRY(mod2),ch);
		

		sprintf(nom,"%s",p.nom);
		gtk_entry_set_text(GTK_ENTRY(mod3),nom);

		if(strcmp(p.type,"petit_dejeuner") == 0){
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),0);
		}
		else if(strcmp(p.type,"dejeuner") == 0){
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),1);
		}
		else{
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),2);
		}
		
	}
	
}


void
on_affichage_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*treeview;
	
	window1 = lookup_widget(objet,"liste_menu");
	
	treeview = lookup_widget(window1,"treeviewFarah");
		
	afficher(treeview);
}

void
on_retourMeui_farah_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"meilleur_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_trouverM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *id_l,*nom_l,*jd,*md,*ad,*ja,*ma,*aa ; 
		date d1,d2;

	
		jd = lookup_widget(objet,"JD");
		md = lookup_widget(objet,"MD");
		ad = lookup_widget(objet,"AD");

		d1.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jd));
		d1.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(md));
		d1.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ad));


		ja = lookup_widget(objet,"JA");
		ma = lookup_widget(objet,"MA");
		aa = lookup_widget(objet,"AA");

		d2.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ja));
		d2.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ma));
		d2.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aa));

		id_l = lookup_widget(objet,"id_menu");
		nom_l = lookup_widget(objet,"nom_Mmenu");

	
		


		char sid[20],snom[20];
		sprintf(sid,"%d",meuilleur_menu(d1,d2).id);
		gtk_label_set_text(GTK_LABEL(id_l),sid);	


		sprintf(snom,"%s",meuilleur_menu(d1,d2).nom);
		gtk_label_set_text(GTK_LABEL(nom_l),snom);
}

