#include<stdio.h>
#include "1.c"
#include "matrix.c"

void BFS(int);
int visited[10];

int main()
{
	graphInput();
	graphShow();
	int v;
	printf("Enter the Vertex:\n");
		scanf("%d",&v);
	BFS(v);
	return 0;
}

void BFS(int v)
{
	int i,j;

	for(i=0; i<v; i++)
		visited[i] = 0;	
	
	insert(v);
	visited[v]=1;

	while(!isEmpty())
	{
		i=delete();
		printf("%5c",i+'A');

		for(j=0;j<n;j++){

			if(visited[j] == 0){
				insert(j);
				visited[j] = 1;
			}
		}
									
	}
}


