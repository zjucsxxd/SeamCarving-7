#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

int main()
{
	//Entrée manuelle du tableau im	
	int nc,nl,nbcol;
	unsigned char** im = NULL;
	unsigned char** ims = NULL;
	unsigned char** imz = NULL;

	printf("Entrez manuellement le tableau représentant l'image de base.\n");
	printf("Nombre de ligne : ");
	scanf("%d", &nl);
	printf("Nombre de colonne :");
	scanf("%d", &nc);

	im = alloue_image_char(nl,nc);
	printf("Entrez les éléments :\n");
	for (i=0;i++;i<nl)
	{
		for (j=0;j++;j<nc)
		{
			printf("(%d,%d) : ",i,j);
			scanf("%c", &(im[i][j]));
		}
	}

	
	printf("Réduire l'image de combien de colonnes ? ");
	scanf("%d", &nbcol);
	ims = seam_carving(im,nbcol,nl,nc);
	imz = zoomx(im,nbcol,nl,nc);
}
