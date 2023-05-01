//Write a program in C or C++ to find a given key in array using ternary Search algorithm.
#include <stdio.h>
#include <stdlib.h>

int Search (int x[], int l, int r, int key){
	
	if (l <= r){

		int mid1 = l+((r-l)/3);
		int mid2 = r-((r-l)/3);
		
		if (x[mid1] == key)
			return mid1;
		else if (x[mid2] == key)
			return mid2;
		else if (key < x[mid1])
			return Search (x, l, mid1−1, key);
		else if (key > x[mid2])
			return Search (x, mid2+1, r, key);
		else
			return Search (x, mid1+1, mid2−1, key);
	}
	return -1;		
}	

int main(){
	
	int n, key;
	printf("Enter the size of the array");
	scanf("%d", &n);
	
	if(n >= 1){
		int x[n];
		printf("Enter the array elements");
		
		for (int i=0; i<n; i++)
			scanf ("%d", x[i]);

		printf("Enter the key value");
		scanf ("%d", &key);

		int ans = Search(x, 0, n-1, key);
		if(ans != -1)
			printf("Element found! at position %d", key, ans+1);
		else
			printf ("Element not found");
	}

	printf ("The array size should be greater or equal to 1");
	return 0;
}	
