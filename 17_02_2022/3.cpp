// Write a program in C or C++ to find GCD of two numbers using recursion


#include <iostream>
#include <stdlib.h>
using namespace std;
int gcd(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b) return a;
	if (a > b) return gcd(a-b, b);
	else return gcd(a, b-a);
}

int main(){
	
	cout << "Enter two numbers: " << endl;
	int n, m;
	cin >> n >> m;

	cout << "GCD of the two numbers: " << gcd(n, m)	 << endl;
}


