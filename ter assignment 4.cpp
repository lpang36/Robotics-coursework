#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

//get integer in range
int getInt (int low, int high = INT_MAX) {
	int n = low-1;
	//sentinel loop
	while (n<low||n>high) {
		//prompt for input
		if (high!=INT_MAX) {
			cout << "Enter a value between " << low << " and " << high << " (inclusive): ";
		}
		//keep default high value
		else {
			cout << "Enter a value greater than or equal to " << low << ": ";
		}
		cin >> n;
		//prompt to try again
		if (n<low||n>high) {
			cout << "Not within range. Please try again.\n";
		}
	}
	return n;
}

//calculate sum of integers 
int sumLimit (int n) {
	return (n*(n+1))/2;
}

//decide if an integer is prime
bool prime (int n) {
	int i;
	bool isPrime = true;
	//special case
	if (n==1) {
		return false;
	}
	//loop through all integers up to n/2 
	for (i=2; i<=n/2; i++) {
		//if test value divides into n, n is not prime
		if (isPrime&&n%i==0) {
			isPrime = false;
		}
	}
	return isPrime;
}

//calculate quadratic roots
bool quadratic (int a, int b, int c, double &x1, double &x2) {
	//if discriminant is negative, no solution
	if (b*b-4*a*c<0) {
		return false;
	}
	//find roots with quadratic formula
	if (a!=0) {
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	}
	//special case
	else {
		x1 = -c/(b+0.0);
		x2 = -c/(b+0.0);
	}
	return true;
}

//test getInt program
void getIntTest() {
	int low, high, choice, n;
	//prompt for low and high values
	cout << "Enter low value: ";
	cin >> low;
	//offer choice to keep default high value
	cout << "Enter 0 to use default high value, or any other number to enter a custom high value: ";
	cin >> choice;
	if (choice!=0) {
		high = getInt(low);
		n = getInt(low, high);
	}
	else {
		n = getInt(low);
	}
	//display output
	cout << "Your integer was " << n << ".\n";
}

//test sumLimit program
void sumLimitTest() {
	int n;
	//prompt for input
	n = getInt(1);
	//display sum
	cout << "The sum of integers up to " << n << " is " << sumLimit(n) << ".\n";
}

//test prime program
void primeTest() {
	int n;
	//prompt for input
	n = getInt(1);
	//display whether integer is prime
	if (prime(n)) {
		cout << n << " is prime.\n";
	}
	else {
		cout << n << " is not prime.\n";
	}
}

//test quadratic program
void quadraticTest() {
	int a, b, c;
	double x1, x2;
	bool solution;
	//prompt for coefficients
	cout << "Enter the quadratic term coefficient: ";
	cin >> a;
	cout << "Enter the linear term coefficient: ";
	cin >> b;
	cout << "Enter the constant term: ";
	cin >> c;
	solution = quadratic(a,b,c,x1,x2);
	//display solutions or lack thereof
	if (solution) {
		cout << "X1 = " << x1 << "\nX2 = " << x2 << "\n";
	}
	else {
		cout << "There are no real roots.\n";
	}
}

//main menu
int main(){
	while (true) {
		//input choice of program
		int choice;
		cout << "Enter a number to select a program: \n";
		cout << "1 - getInt\n";
		cout << "2 - sumLimit\n";
		cout << "3 - prime\n";
		cout << "4 - quadratic\n";
		cin >> choice;
		system("CLS");
		if (choice==1) {
			getIntTest();
		}
		else if (choice==2) {
			sumLimitTest();	
		}
		else if (choice==3) {
			primeTest();
		}
		else if (choice==4) {
			quadraticTest();
		}
		//return to menu
		cout << "\nPress enter to return to home screen.";
		getch();
		system("CLS");
	}
	return 0;
}
