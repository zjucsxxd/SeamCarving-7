#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL_phelma.h>
#include "projet.h"


int main(int ac, char**av) 
{ 
	int nl, nc, i,j;
	unsigned char** im, ** im2;
	unsigned char* p1,*p2;
	unsigned int ** im3;

	printf("Entrer les dimensions (nblignes puis nbcolonnes) des matrices a creer :"); 
	fflush(stdout);
	scanf("%d %d",&nl,&nc);
	if (nl <=0 || nc <=0) 
	{
		printf("nblignes et nbcolonnes : Pas de valeurs negatives\n"); 
		exit(1); 
	}
	printf("Creation d'une matrice d'octets de %d lignes et %d colonnes : ",nl,nc); fflush(stdout);
	im=alloue_image_char(nl,nc);
	if (im==NULL) 
	{ 
		printf("Allocation impossible\n"); 
		exit(1); 
	}
	puts("--> OK");

	printf("Test des valeurs de la matrice : acces par indice i,j"); fflush(stdout);
	for (i=0; i<nl; i++) for(j=0; j<nc; j++) im[i][j]=(i+j)%256;
	puts("--> OK");

	im2=alloue_image_char(nl,nc);
	printf("Test des valeurs de la matrice : allocation contigue");
	fflush(stdout);
	for (p1=*im,p2=*im2,i=0; i<nl*nc; i++) p2[i]=p1[i];
	puts("--> OK");

	printf("Test de la liberation de la matrice");
	fflush(stdout);
	libere_image(im);
	puts("--> OK");
 
	printf("Creation d'une matrice d'entiers de %d lignes et %d colonnes: ",nl,nc); 
	fflush(stdout);
	im3=alloue_image_int(nl,nc);
	if (im==NULL) 
	{ 
		printf("Allocation impossible\n"); 
		exit(1); 
	}
	puts("--> OK");

	printf("Test des valeurs de la matrice : acces par indice i,j"); 
	fflush(stdout);
	for (i=0; i<nl; i++) for(j=0; j<nc; j++) im3[i][j]=(i+j);
	puts("--> OK");

	printf("Test de la liberation de la matrice"); 
	libere_image((unsigned char**)im3); 
	puts("Test de la liberation de la matrice : OK");
}
