// Write a program in C or C++ to find the largest element of an array using recursion.

#include <iostream>
#include <stdlib.h>
using namespace std;

int findLargest(int arr[], int n){
	if (n == 1) return arr[0]; //if number of elements =1
	return max(arr[n-1], findLargest(arr, n-1));
}

int main(){
	
	int n;
	cout << "Enter the number of elements: "<< endl;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++)
		cin >> arr[i];
	cout << "Largest element in the array is: " << findLargest(arr, n) << endl;
}
