#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

int main()
{
	//Entrée manuelle du tableau im	
	int nc,nl,nbcol;
	int i,j;
	unsigned char** im = NULL;
	unsigned char** ims = NULL;
	unsigned char** imz = NULL;

	printf("Entrez manuellement le tableau représentant l'image de base.\n");
	printf("Nombre de ligne : ");
	nl = lire();
	printf("Nombre de colonne :");
	nc=lire();
	im = alloue_image_char(nl,nc);
	printf("Entrez les éléments :\n");
	for (i=0;i<nl;i++) 
	{
		for (j=0;j<nc;j++)
		{
			printf("(%d;%d) : ", i, j);
			im[i][j] = (char) lire();
		}
	}
	printf("Réduire l'image de combien de colonnes ? ");
	nbcol=lire();

	ims = seam_carving(im,nbcol,nl,nc);
	imz = zoomx(im,nbcol,nl,nc);
	
	libere_image_char(im);
	libere_image_char(ims);
	libere_image_char(imz);
	
	
}
