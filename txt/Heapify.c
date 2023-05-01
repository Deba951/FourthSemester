#include <stdio.h>

void swap(int arr[], int i, int largest)
{
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
}
int m=1;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
    printf("\n\n");
    printf("Pass:%d is--> ",m);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //printf("\n");
    m++;
}
void heapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = (n - 1); i >= 0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements-->\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sorting-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    heapSort(a, n);
    printf("\nThe array after sorting-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}