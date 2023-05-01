#include <stdio.h>

void maxMin(int a[],int i,int j,int *max,int *min){
    int max1,mid,min1;
    if(i==j){
        *max=a[i];
        *min=a[i];
    }
    else if(i==j-1){
        if(a[i]>a[j]){
            *max=a[i];
            *min=a[j];
        }
        else{
            *max=a[j];
            *min=a[i];
        }
    }
    else{
        int mid=(i+j)/2;
        maxMin(a,i,mid,max,min);
        maxMin(a,mid+1,j,&max1,&min1);
        if(*max<max1){
            *max=max1;
        }
        if(*min>min1){
            *min=min1;
        }
    }
}
int main()
{
    int n,max,min;
    printf("Enter the size of the array--> ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements-->\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    maxMin(a,0,n-1,&max,&min);
    printf("The max element of the array is-->%d\n",max);
    printf("The min element of the array is-->%d\n",min);
    return 0; 
}