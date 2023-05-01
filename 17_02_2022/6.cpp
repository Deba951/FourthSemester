// Write a program in C or C++ to check a number is a prime number or not using recursion.

#include <iostream>
#include <stdlib.h>

using namespace std;

int isPrime(int n, int i){ // first calling from main, isPrime(n,2) ,initial value of i=2
	if (n <= 2) return (n == 2) ? 1 : 0;
	if (n % i == 0) return 0;
	if (i * i > n) return 1;
	return isPrime(n, i + 1);
}

int main(){
				
}
