// 1. Write a program in C or C++ to find the sum of digits of a number using recursion

#include <iostream>
#include <stdlib.h>
using namespace std;

int sumOfDigit(int n){
	if (n == 0) return 0;
	return (n % 10 + sumOfDigit(n / 10));
}

int main(){
	system("clear");
	int n, sum;
	cout << "Enter any number: " ;
	cin >> n;
	
	sum = sumOfDigit(n);
	cout << "Sum of the digits is:  " << sum;
}
