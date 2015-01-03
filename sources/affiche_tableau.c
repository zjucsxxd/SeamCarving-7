#include <stdio.h>
#include <stdlib.h>

void afficheTab(unsigned char **tab,int nl, int nc)
{
	int i,j;
	for (i=0;i<nl;i++)
	{
		printf("|");
		for (j=0;j<nc;j++)
		{
			printf("    %d    |",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
