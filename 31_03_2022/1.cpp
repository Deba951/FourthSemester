#include<iostream>
using namespace std;


void adjustheap(int a[], int i, int n){
	int j=2*i;
	int key=a[i];
	while(j<=n){
		if(j<n && a[j]<a[j+1])
			j=j+1;
		if(key>=a[j])
			break;
		a[j/2]=a[j];
		j=2*j;	
	}
	a[j/2]=key;
}


int makeheap(int a[], int n){
	for (int i=n/2; i>=1; i--)
		adjustheap(a, i, n);
}


void heapsort(int a[], int n){			
	makeheap(a, n);
	for(int i=n; i>=2; i--){
		int temp = a[i];
		a[i] = a[1];
		a[i] = temp;
		adjustheap(a, 1, i-1);
	}
}


int main(){
	int n;
	cout << "Enter the size: " << endl;
	cin >> n;
	int a[n];
	cout << "Enter the elements: " << endl;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cout << "Before sorting: ";
	for (int i=0; i<n; i++)
		cout << a[i] << "\t";
	heapsort(a, n);
	cout << "\nAfter Sorting: ";
	for (int i=0; i<n; i++)
		cout << a[i] << "\t";
	return 0;
}
