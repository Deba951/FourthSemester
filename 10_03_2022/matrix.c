#include<stdio.h>
int matrix[10][10],n;
int graphInput(){

	FILE *fp;
	fp = fopen ("Text.txt", "r");

	if (fp == NULL){
		
		printf ("UNABLE TO LOCATE FILE \n");
		return 0;
	}
	fscanf(fp,"%d", &n);
	
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			fscanf(fp, "%d", &matrix[i][j]);
		}	
	}
	fclose(fp);
return 0;
}

void graphShow()
{
int i,j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			printf ("%5d\t", matrix[i][j]);

		printf("\n\n");		
	}
}