// Write a program in C or C++ to reverse of digits of a number using recursion.

#include <iostream>
#include <stdlib.h>
using namespace std;

int reverse(int n, int temp){
	if (n == 0) return temp; // base case
	temp = (temp * 10) + (n % 10); // reverse of a number
	return reverse(n / 10, temp);
	}

int main(){

	system("clear");
	int n, temp = 0;
	cout << "Enter the number: " << endl;
	cin >> n;
	cout << "Reversed Number: " << reverse(n, temp) << endl;
}
	


