#include <stdio.h>
#include <limits.h>

int m[40][40], s[40][40], size;
void pop(int (*s)[40], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        pop(s, i, s[i][j]);
        pop(s, s[i][j] + 1, j);
        printf(")");
    }
}
void display_table(int (*arr)[40], int size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}
void mcm(int arr[])
{
    int n = size;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= (n - len + 1); i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= (j - 1); k++)
            {
                int cost = m[i][k] + m[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nFinal M table is-->\n");
    display_table(m, size);
    printf("\nFinal S table is-->\n");
    display_table(s, size);
    printf("\nTotal number of scalar multiplication-->%d", m[1][size]);
    printf("\nThe optimal order is-->");
    pop(s, 1, size);
}
int main()
{
    printf("Enter the number of matrices--> ");
    scanf("%d", &size);
    int a[size];
    printf("\nEnter the row number for each matrix and row & coloumn for last one-->\n");
    for (int i = 0; i <= size; i++)
    {
        scanf("%d", &a[i]);
    }
    mcm(a);
    return 0;
}