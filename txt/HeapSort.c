#include <stdio.h>

int m = 1;
void adjustHeap(int arr[], int i, int n)
{
    int j = 2 * i, key = arr[i];
    while (j <= n)
    {
        if (j < n && arr[j] < arr[j + 1])
        {
            j = j + 1;
        }
        if (key >= arr[j])
        {
            break;
        }
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = key;
    // printf("\n\n");
    // printf("Pass:%d is--> ",m);
    // for(int i=1;i<=n;i++){
    //     printf("%d ",arr[i]);
    // }
    // //printf("\n");
    // m++;
}
void makeHeap(int arr[], int n)
{
    for (int i = (n / 2); i >= 1; i--)
    {
        adjustHeap(arr, i, n);
    }
}
void HeapSort(int arr[], int n)
{
    makeHeap(arr, n);
    for (int i = n; i >= 2; i--)
    {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        adjustHeap(arr, 1, i - 1);

        printf("\n\n");
        printf("Pass:%d is--> ", m);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", arr[i]);
        }
        // printf("\n");
        m++;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements-->\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sorting-->\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    HeapSort(a, n);
    printf("\nThe array after sorting-->\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}