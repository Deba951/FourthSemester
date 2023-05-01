#include <stdio.h>

int q[100], gr[100][100], visited[100], front = -1, rear = -1, n;

int isEmpty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}
void insert(int item)
{
    rear = rear + 1;
    q[rear] = item;
}
int delete()
{
    front = front + 1;
    return q[front];
}

void BFS(int v)
{
    int u;
    for (u = 0; u <= v - 1; u++){
        visited[u] = 0;
    }
    insert(v);
    visited[v] = 1;
    while (!isEmpty())
    {
        u = delete ();
        printf("%2c", u +65);
        for (int j = 0; j < n; j++)
        {
            if (gr[u][j] == 1)
            {
                if (visited[j] == 0)
                {
                    insert(j);
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
    char s;
    fp = fopen("bfs.txt", "r");
    if (fp == NULL)
    {
        printf("\nError to open the file\n");
    }
    else
    {
        fscanf(fp, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &gr[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &n);
        getchar();
        printf("\nEnter the starting vertex--> ");
        scanf("%c", &s);

        if ((int)s - 65 >= 0 && (int)s - 65 <= n - 1)
        {
            printf("\nThe BFS traversal of the graph is : ");
            BFS((int)s - 65);
        }
        else
            printf("\nInvalid Input !");
    }
}