#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

int main(int argc, char *argv[])
{
	int nc,nl,nbcol;
	int i,j;
	unsigned char** im = NULL;
	unsigned char** ims = NULL;
	unsigned char** imz = NULL;
	int test = 0;
	//test = lire();	

	if (test == 1) //Tableau de test pré-rentré
	{
		im = alloue_image_char(6,7);
		nl = 6;
		nc = 7;
	
		im[0][0]=195;
		im[0][1]=196;
		im[0][2]=196;
		im[0][3]=197;
		im[0][4]=197;
		im[0][5]=197;
		im[0][6]=197;
		im[1][0]=184;
		im[1][1]=187;
		im[1][2]=189;
		im[1][3]=191;
		im[1][4]=192;
		im[1][5]=193;
		im[1][6]=194;
		im[2][0]=183;
		im[2][1]=184;
		im[2][2]=185;
		im[2][3]=86;
		im[2][4]=187;
		im[2][5]=187;
		im[2][6]=188;
		im[3][0]=173;
		im[3][1]=174;
		im[3][2]=62;
		im[3][3]=143;
		im[3][4]=174;
		im[3][5]=176;
		im[3][6]=178;
		im[4][0]=172;
		im[4][1]=169;
		im[4][2]=137;
		im[4][3]=99;
		im[4][4]=157;
		im[4][5]=174;
		im[4][6]=176;
		im[5][0]=178;
		im[5][1]=188;
		im[5][2]=173;
		im[5][3]=193;
		im[5][4]=176;
		im[5][5]=180;
		im[5][6]=180;
		

		printf("Image de départ : \n");
		afficheTab(im, nl, nc);
		printf("Réduire l'image de combien de colonnes ? ");
		nbcol=lire();

		ims = seam_carving(im,nbcol,nl,nc);
		printf("\nImage réduite par SeamCarving :\n");
		afficheTab(ims,nl,nc-nbcol);
	
	
		imz = zoomx(im,nbcol,nl,nc);
		printf("Image zoomée linéairement :\n");
		afficheTab(imz,nl,nc-nbcol);
	
		libere_image_char(im);
		libere_image_char(ims);
		libere_image_char(imz);

	}

	else if (test == 0)
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Surface *screen = NULL;
		SDL_Surface *sm=NULL;
		SDL_Surface *zx=NULL;

		im = lire_image(argv[1], &nl, &nc);

		SDL_Rect positionS;
		positionS.x=0;
		positionS.y=0;
		SDL_Rect positionZ;
		positionZ.x=0;
		positionZ.y=nl;
	
		screen = SDL_SetVideoMode(nc,2*nl,32,SDL_HWSURFACE | SDL_RESIZABLE);
		SDL_WM_SetCaption("SeamCarving",argv[1]); 
		SDL_WM_SetIcon(SDL_LoadBMP(argv[1]), NULL);

		sm = SDL_CreateRGBSurface(SDL_HWSURFACE, nc, nl, 32, 0, 0, 0, 0);
		zx = SDL_CreateRGBSurface(SDL_HWSURFACE, nc, nl, 32, 0, 0, 0, 0);


		dessiner(im,screen,sm, positionS, nl, nc);
		dessiner(im,screen,zx, positionZ, nl, nc);

			
		int continuer =1;
		SDL_Event event;
		while (continuer)
		{	
			SDL_WaitEvent(&event);
			switch(event.type)
			{
				case SDL_QUIT :
					continuer = 0;
					break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							continuer=0;
							break;

						default:
							break;
					}		
					break;

				case SDL_VIDEORESIZE:
					nl = event.resize.h;
					nc = event.resize.w;
					break;
			}
			
			//dessiner(im,screen,sm, positionS, nl, nc);
			//dessiner(im,screen,zx, positionZ, nl, nc);
			SDL_Flip(screen);
		}	



		
		SDL_FreeSurface(sm);
		SDL_FreeSurface(zx);
		SDL_Quit();

		libere_image_char(im);
		libere_image_char(ims);
		libere_image_char(imz);
	}
	else  //Entrée manuelle du tableau
	{
		printf("\n\n\nEntrez manuellement le tableau représentant l'image de base.\n");
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

		printf("Image de départ : \n");
		afficheTab(im, nl, nc);
		printf("Réduire l'image de combien de colonnes ? ");
		nbcol=lire();

		ims = seam_carving(im,nbcol,nl,nc);
		printf("\nImage réduite par SeamCarving :\n");
		afficheTab(ims,nl,nc-nbcol);
	
	
		imz = zoomx(im,nbcol,nl,nc);
		printf("Image zoomée linéairement :\n");
		afficheTab(imz,nl,nc-nbcol);
	
		libere_image_char(im);
		libere_image_char(ims);
		libere_image_char(imz);

	}	
	

		
	
	
	return EXIT_SUCCESS;	
}
