#include <stdio.h>

int n,m=1;
void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int b[high-low+1];
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=high){
        b[k++]=a[j++];
    }
    for(int p=low;p<=high;p++){
        a[p]=b[p];
    }
    printf("\n");
    printf("Pass:%d--> ",m);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    m++;
}
void mergeSort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    printf("Enter then size of the array--> ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements-->\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array before sorting--> \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    mergeSort(a,0,n-1);
    printf("The array before sorting--> \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0; 
}