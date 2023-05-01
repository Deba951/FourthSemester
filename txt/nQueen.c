#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int x[100], c = 0;
char place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
        {
            return false;
        }
    }
    return true;
}
void print(int n)
{
    printf("\n\nSolution:%d-->\n\n", ++c);
    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }
        }
    }
}
void nQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                print(n);
            }
            else
            {
                nQueen(k + 1, n);
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of queens--> ");
    scanf("%d", &n);
    nQueen(1, n);
    if (c == 0)
    {
        printf("No such solutions exist!!!");
    }
    return 0;
}