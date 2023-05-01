#include <stdio.h>
#define v 6
struct edge{
    char vertex1;
    char vertex2;
    int weight;
};
struct edge e[100];
// int makeset[v + 1];
int makeset[v];

void mergeedges(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    struct edge b[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (e[i].weight <= e[j].weight)
        {
            b[k++] = e[i++];
        }
        else
        {
            b[k++] = e[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = e[i++];
    }
    while (j <= high)
    {
        b[k++] = e[j++];
    }
    k = 0;
    for (int p = low; p <= high; p++)
    {
        e[p] = b[k++];
    }
}
void mergesort_edges(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort_edges(low, mid);
        mergesort_edges(mid + 1, high);
        mergeedges(low, mid, high);
    }
}
int collapsingFind(int i)
{
    int r = i;
    while (makeset[r] > 0)
    {
        r = makeset[r];
    }
    while (i != r)
    {
        int temp = makeset[i];
        makeset[i] = r;
        i = temp;
    }
    return r;
}
void weightedUnion(int i, int j)
{
    int a = collapsingFind(i);
    int b = collapsingFind(j);
    int count = makeset[a] + makeset[b];
    if (makeset[a] <= makeset[b])
    {
        makeset[b] = a;
        makeset[a] = count;
    }
    else
    {
        makeset[a] = b;
        makeset[b] = count;
    }
}
void kruskal(int e1)
{
    int wt = 0;
    printf("The vertices in the MST are-->\n");
    for (int i = 0; i < e1; i++)
    {
        if (collapsingFind((int)e[i].vertex1 - 65) != collapsingFind((int)e[i].vertex2 - 65))
        {
            printf("%c-->%c\n", e[i].vertex1, e[i].vertex2);
            wt += e[i].weight;
            weightedUnion((int)e[i].vertex1 - 65, (int)e[i].vertex2 - 65);
        }
    }
    printf("Weight of the MST is-->%d", wt);
}
int main()
{
    int e2;
    printf("Enter the number of edges--> ");
    scanf("%d", &e2);
    printf("Enter the connected vertices and their respective weights-->\n");
    for (int i = 0; i < e2; i++)
    {
        getchar();
        printf("\nEnter vertex1 and vertex2: ");
        scanf("%c %c", &e[i].vertex1, &e[i].vertex2);
        printf("Enter the weight: ");
        scanf("%d", &e[i].weight);
    }
    for (int i = 0; i < v; i++)
    {
        makeset[i] = -1;
    }
    mergesort_edges(0, e2 - 1);
    kruskal(e2);
    return 0;
}