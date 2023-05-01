#include <stdio.h>
#include <limits.h>

struct graph
{
    int weight;
    char precedence;
};
struct graph g[100];
int k, G[100][100];
void path(int i)
{
    if (g[i].precedence == 'N')
    {
        return;
    }
    else
    {
        path((int)g[i].precedence - 64);
        printf(" %c to %c", g[i].precedence, (char)(i + 64));
    }
}
void print(int s)
{
    for (int i = 1; i <= k; i++)
    {
        if (i != s)
        {
            printf("\nVertex %c : ", (char)(i + 64));
            path(i);
            if (g[i].weight != INT_MAX)
            {
                printf("(The cost is-->%d)", g[i].weight);
            }
            else
            {
                printf("(The cost is infinite)");
            }
        }
    }
}
char bellman(int s)
{
    for (int i = 1; i <= k; i++)
    {
        g[i].weight = INT_MAX;
        g[i].precedence = 'N';
    }
    g[s].weight = 0;
    for (int p = 1; p < k; p++)
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (G[i][j] != 0 && g[i].weight != INT_MAX && g[i].weight + G[i][j] < g[j].weight)
                {
                    g[j].weight = g[i].weight + G[i][j];
                    g[j].precedence = (char)(i + 64);
                }
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (G[i][j] != 0 && g[i].weight != INT_MAX && g[i].weight + G[i][j] < g[j].weight)
            {
                return 'F';
            }
        }
    }
    return 'T';
}
int main()
{
    FILE *fp;
    char r;
    fp = fopen("bellman1.txt", "r");
    if (fp == NULL)
    {
        printf("Error to open the file!!!");
    }
    else
    {
        fscanf(fp, "%d", &k);
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                fscanf(fp, "%d", &G[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &k);
        printf("Enter the starting vertex--> ");
        getchar();
        scanf("%c", &r);
        char c = bellman((int)r-64);
        if (c == 'T')
        {
            printf("\nThe shortest path from vertex %c to all other vertices are-->\n", r);
            print((int)r-64);
        }
        else
        {
            printf("\nNegettive edge cycle occurs!!!\n");
        }
    }
    return 0;
}