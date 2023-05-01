#include<bits/stdc++.h>
using namespace std;

struct item{
	int value, weight;	
	item(int value, int weight){
		this -> value =value;
		this -> weight = weight;
	}
};

bool compare(struct item a, struct item b){
	double r1 = (double)a.value/(double)a.weight;
	double r2 = (double)b.value/(double)b.weight;
	return r1>r2;
}

double fractionalknapsack(int w, struct item arr[], int n){
	
	sort(arr, arr+n, compare);

	for(int i=0; i<n; i++)
		cout << arr[i].value << " " << arr[i].weight << " : " << ((double)arr[i].value/(double)arr[i].weight) << endl;

	int currweight = 0;
	double finalvalue = 0.0;
	
	    for(int i=0; i<n; i++){
			if(currweight + arr[i].weight <= w){
				currweight+=arr[i].weight;
				finalvalue+=arr[i].value;
		}
		else{
		int remainder=w-currweight;
		finalvalue+=arr[i].value+((double)remainder/(double)arr[i].weight);
		break;
		}
	}
	return finalvalue;
}

int main(){
	int w=15;
	item arr[] = {{10,2}, {5,3}, {15,5}, {7,7}, {6,1}, {18,4}, {3,1}};	
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum value we can obtain = " << fractionalknapsack << (w, arr, n) << endl;
	return 0;
}
