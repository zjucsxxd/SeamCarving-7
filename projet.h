#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL_phelma.h>

unsigned int** alloue_image_int(int nl, int nc);
unsigned char** alloue_image_char(int nl, int nc);
void libere_image(unsigned char** im);
unsigned char** zoomx_image(unsigned char **ims, unsigned char **im, int nbcol, int jc, int nl, int nc); 
unsigned char** gradient(unsigned char** img, unsigned char** im, int nl, int nc); 
void calcul_cout(unsigned char** energie, unsigned int** pere, unsigned int* coutfinal,int nl, int nc); 
int trouve_chemin(unsigned int* ch_max, unsigned int** pere, unsigned int* coutfinal, int nl, int nc);
unsigned char** trace_chemin(unsigned char** im2, unsigned int* ch, int cl, int nl, int nc); 
void supprime_colonne(unsigned char** im, unsigned int* ch_max,int nl, int* pnc); 
unsigned char** seam_carving(unsigned char** im, int nbcol, int nl, int nc);
unsigned char** seam_carving_graphique(SDL_Surface* fenetre, unsigned char** im, int nbcol, int nl, int nc);
unsigned char** gradienty(unsigned char** img,unsigned char** im, int nl, int nc);
