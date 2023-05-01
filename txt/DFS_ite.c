#include <stdio.h>

int s[100], gr[100][100], visited[100], top = -1, n;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int item)
{
    top = top + 1;
    s[top] = item;
}

int pop()
{
    return s[top--];
}

void DFS(int v)
{
    int u;
    for (u = 0; u <= v - 1; u++)
        visited[u] = 0;
    push(v);
    visited[v] = 1;
    while (!isEmpty())
    {
        u = pop();
        printf("%2d", u);
        int j;
        for (j = 1; j <= n; j++)
        {
            if (gr[u][j] == 1)
            {
                if (visited[j] == 0)
                {
                    push(j);
                    visited[j] = 1;
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    FILE *fp;
    int s;
    fp = fopen("dfs.txt", "r");
    if (fp == NULL)
    {
        printf("\nError to open the file\n");
    }
    else
    {
        fscanf(fp, "%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                fscanf(fp, "%d", &gr[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &n);
        printf("\nEnter the starting vertex--> ");
        scanf("%d", &s);

        if (s >= 1 && s <= n)
        {
            printf("\nThe BFS traversal of the graph is : ");
            DFS(s);
        }
        else
            printf("\nInvalid Input !");
    }
}