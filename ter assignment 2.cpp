#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

//display list of squares
void square(){
	//input integer
	int num, i;
	cout << "Enter an integer: ";
	cin >> num;
	cout << "\nNumber\tSquare\n";
	//loop through squares up to the inputted integer
	for (i=1; i<=num; i++) {
		cout << i << "\t" << pow(i,2) << "\n";
	}
}

//display product of a series of numbers
void product(){
	//input number
	int prod, num, i, temp;
	prod = 1;
	cout << "How many numbers to process? ";
	cin >> num;
	//check if number is positive
	if (num>0) {
		cout << "\nEnter " << num << " positive integers\n";
		//input series of numbers
		for (i=0; i<num; i++) {
			int temp;
			cout << "#" << i+1 << ": ";
			cin >> temp;
			//check if number is positive
			if (temp>0) {
				prod = prod*temp;
			}
			else {
				cout << temp << " not counted\n";
			}	
		}
		//display product
		cout << "\nThe product of the positives is " << prod << ".\n";
	}
	else {
		cout << "Improper input.\n";
	}
}

//calculate factorial of a number
void factorial(){
	int num, i;
	//unsigned long long has the highest upper limit
	unsigned long long prod;
	prod = 1;
	//input number
	cout << "Enter a non-negative integer: ";
	cin >> num;
	cout << "\n";
	//check if number is too large or too small
	if (num<0) {
		cout << "Number is too small.\n";
	}
	else if (num>20) {
		cout << "Number is too large.\n";
	}
	else if (num==1) {
		//special format for 1!
		cout << "1 = 1\n";
	}
	else {
		//calculate factorial and display steps
		for (int i = num; i>0; i--) {
			cout << i << " ";
			if (i!=1) {
				cout << "x ";
			}
			prod = prod*i;
		}
		cout << "= " << prod << "\n";
	}
}

//calculate bank balance with compound interest
void invest() {
	//input deposit, interest rate, and term
	double deposit, rate, term, balance, interest;
	balance = 0;
	interest = 0;
	int i;
	cout << "Monthly Deposit          : ";
	cin >> deposit;
	cout << "Annual Interest Rate (%) : ";
	cin >> rate;
	cout << "Term (Months)            : ";
	cin >> term;
	cout << "\n";
	//display table
	cout << "Starting    Interest      Monthly       Ending\n";
	cout << "Balance       Earned      Deposit      Balance\n";
	cout << "--------    --------     --------     --------\n";
	for (i=0; i<term; i++) {
		//calculate interest and balance
		printf ("%7.2f", balance);
		interest = balance*(rate/1200);
		printf ("%13.2f", interest);
		printf ("%13.2f", deposit);
		balance = balance+interest+deposit;
		printf ("%13.2f \n", balance);
	}
}

//main menu
int main(){
	while (true) {
		//input choice of program
		int choice;
		cout << "Enter a number to select a program: \n";
		cout << "1 - Square\n";
		cout << "2 - Product\n";
		cout << "3 - Factorial\n";
		cout << "4 - Invest\n";
		cin >> choice;
		system("CLS");
		if (choice==1) {
			square();
		}
		else if (choice==2) {
			product();	
		}
		else if (choice==3) {
			factorial();
		}
		else if (choice==4) {
			invest();
		}
		//return to menu
		cout << "\nPress enter to return to home screen.";
		getch();
		system("CLS");
	}
	return 0;
}
