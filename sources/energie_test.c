#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL_phelma.h>
#include "projet.h"


main(int ac, char**av) { int nl, nc;
  unsigned char** im, ** im3, **im4, **energ;
  
  puts("Test du calcul de l'energie de l'image");
  if ((ac != 2) || av[1]==NULL || 
      (im=lectureimage8(av[1],&nl,&nc))==NULL){
      printf("Usage : %s fichier_image_entree\n",av[0]); exit(1); 
  }

  printf("Creation d'une image energie "); fflush(stdout);
  energ=alloue_image_char(nl,nc);
  if (energ==NULL) printf("Allocation impossible pour l'image energie "); 
  puts("--> OK");
  printf("Test de calcul de l'energie :"); fflush(stdout);
  im4=gradient(energ,im,nl,nc);
  if (im4!=energ) { printf("Erreur : image retournee differente de l'energie : ---> KO\n"); exit(1); }
  puts("--> OK");

  printf("Test de calcul de l'energie : creation d'une image dans la fonction energie "); fflush(stdout);
  im3=gradient(NULL,im,nl,nc);
  if (im3==NULL) printf("Allocation impossible pour l'image energie "); 
  puts("--> OK");
  
  printf("Sauvegarde de l'image d'energie dans le fichier gradient.pgm"); fflush(stdout);
  ecritureimagepgm("gradient.pgm",im3,nl,nc);
  puts("--> OK");

  printf("Liberation image entree "); fflush(stdout);
  libere_image((unsigned char**)im); 
  puts("--> OK");
  printf("Liberation image energie "); fflush(stdout);
  if (energ) libere_image((unsigned char**)energ); 
  puts("--> OK");

  printf("Liberation image 2ieme energie "); fflush(stdout);
  if (im3) libere_image((unsigned char**)im3);
  puts("--> OK");

  return 1;
}
