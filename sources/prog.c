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
		SDL_Surface *image=NULL;
		SDL_Surface *sm=NULL;
		SDL_Rect position;
		position.x=0;
		position.y=0;
		image = SDL_LoadBMP(argv[1]);
		int W = image->w;
		int H = image->h;
		Uint8 r,g,b;
		Uint32 pixel;
		screen = SDL_SetVideoMode(2*W,2*H,32,SDL_HWSURFACE | SDL_RESIZABLE);
		SDL_WM_SetCaption("SeamCarving",argv[1]); 
		SDL_WM_SetIcon(SDL_LoadBMP(argv[1]), NULL);
		sm = SDL_CreateRGBSurface(SDL_HWSURFACE, W, H, 32, 0, 0, 0, 0);

		im = alloue_image_char(H,W);
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				SDL_GetRGB(getpixel(image,j,i), image->format, &r, &g, &b);
				im[i][j]=(unsigned char)r;
			}
		}
		
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				pixel = SDL_MapRGB(sm->format, (Uint8) im[i][j], (Uint8) im[i][j], (Uint8) im[i][j]);
				putpixel(sm,j,i,pixel);
			}
		}
		
		SDL_BlitSurface(sm, NULL, screen, &position);
		SDL_Flip(screen);
		pause();
		printf("Réduire de combien de pixel ?");
		nbcol=lire();
		SDL_Rect positionS;
		positionS.x=0;
		positionS.y=H;
		SDL_Rect positionZ;
		positionZ.x=W;
		positionZ.y=H;
		printf("Image réduite par SeamCarving\n");
		ims = seam_carving(im,nbcol,H,W);
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				pixel = SDL_MapRGB(sm->format, (Uint8) ims[i][j], (Uint8) ims[i][j], (Uint8) ims[i][j]);
				putpixel(sm,j,i,pixel);
			}
		}
		SDL_BlitSurface(sm, NULL, screen, &positionS);
		SDL_Flip(screen);

		pause();




		printf("Image réduite par zoom linéaire\n");
		imz = zoomx(im,nbcol,H,W);
		for (i=0;i<H;i++)
		{
			for (j=0;j<W;j++)
			{
				pixel = SDL_MapRGB(sm->format, (Uint8) imz[i][j], (Uint8) imz[i][j], (Uint8) imz[i][j]);
				putpixel(sm,j,i,pixel);
			}
		}
		SDL_BlitSurface(sm, NULL, screen, &positionZ);
		SDL_Flip(screen);

		pause();
	
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
