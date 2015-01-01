#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

unsigned char** seam_carving(unsigned char** im, int nbcol, int nl, int nc)
{
	if (im == NULL) im = alloue_image_char(nl,nc); //image de base
	int i=0;
	
	for (i=0;i++;i<nbcol)
	{
		
		unsigned char** energie = NULL; //energie de l'image
		unsigned int** pere = NULL; //indication pour chaque case du numéro de colonne par laquelle on est arrivé
		unsigned int* cout_final = NULL; //indication du cout du chemin pour arriver à la derniere case
		unsigned int* ch_max = NULL; //numéro de la colonne pour le chemin correspondant à chaque ligne
		int k=0; //numéro de colonne de la dernière case du chemin
	
		energie = gradienty(energie,im,nl,nc);
		calcul_cout(energie,pere,cout_final,nl,nc);
		k = trouve_chemin(ch_max,pere,cout_final,nl,nc);
		supprime_colonne(im,ch_max,nl,&nc);
	
	}
}
