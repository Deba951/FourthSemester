#include <stdio.h>
#include <stdlib.h>

int main (){
	
	FILE *fp;
	fp = fopen ("Test.txt", "r");

	if (fp == NULL){
		
		printf ("UNABLE TO LOCATE FILE \n");
		return 0;
	}

	int n;
	fscanf(fp,"%d", &n);
	printf("Number of Vertices=%d",n);
	
	int matrix[10][10];
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			fscanf(fp, "%d", &matrix[i][j]);
		}
		printf("\n");		
	}
	
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			printf ("%3d", matrix[i][j]);
		printf("\n");		
	}

	fclose(fp);

	int s=0;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			s=s+matrix[i][j];
	}
	printf("\n Total Degree is: %d", s);

	printf("\n Total number of edges= : %d", s/2);
	printf ("\n");

	
	return 0;
}

