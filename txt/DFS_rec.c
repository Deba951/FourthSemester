#include <stdio.h>

int visited[100]={0}, gr[100][100], n;

void DFS(int a)
{
    visited[a] = 1;
    printf("%d ", a);
    for (int i = 1; i <= n; i++)
    {
        if (gr[a][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void main()
{
    FILE *fp;
    fp = fopen("dfs.txt", "r");
    if (fp == NULL)
    {
        printf("\nError to open the file\n");
    }
    else
    {
        int s;
        fscanf(fp, "%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                fscanf(fp, "%d", &gr[i][j]);
            }
        }
        fclose(fp);
        printf("\nEnter the number of vertices--> ");
        scanf("%d", &n);
        printf("\nEnter the starting vertex--> ");
        scanf("%d", &s);

        if (s >= 1 && s <= n)
        {
            printf("\nThe DFS of the graph is : ");
            DFS(s);
        }
        else
            printf("\nInvalid Input !");
    }
}