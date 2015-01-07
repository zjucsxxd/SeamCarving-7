#include <stdio.h>
#include <stdlib.h>
#include "../headers/projet.h"

int trouve_chemin(unsigned int* ch_max, unsigned int** pere, unsigned int* coutfinal, int nl, int nc)
{
	int i = 0, k = 0;
	unsigned int t = coutfinal[0];
	for (i = 1;i<nc;i++) if (t < coutfinal[i]) k=i;
	if (ch_max == NULL) ch_max = calloc(nl, sizeof(unsigned int));
	ch_max[nl-1]=k;
	for (i= nl-2;i>=0;i--) ch_max[i] = pere[i+1][ch_max[i+1]];
	return k;
}

//#include "projet.h"


/*int trouve_chemin(unsigned int* chemin, unsigned int** pere, unsigned int* cout_final,int nl, int nc){
	if (chemin==NULL) chemin=calloc(nl,sizeof(*chemin));
	int i=0, k=0;
	unsigned int t=cout_final[0];
	for (i=1;i<nc;i++){
		if (t>cout_final[i]){
			t=cout_final[i];
			k=i;
		}
	}
	chemin[nl-1]=k;
	for (i=(nl-2);i>=0;i--){
		chemin[i]=pere[i+1][chemin[i+1]];
	}
	return k;
}*/
