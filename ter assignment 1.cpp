#include <iostream>
#include <conio.h>

using namespace std;

//adds, subtracts, multiplies, and divides two integers
void arithmetic() {
	//input integers
	int a, b;
	cout << "Operand #1: ";
	cin >> a;
	cout << "Operand #2: ";
	cin >> b;
	//calculate sum, difference, product, quotient
	cout << "\n" << a << " + " << b << " = " << a+b << "\n";
	cout << a << " - " << b << " = " << a-b << "\n";
	cout << a << " x " << b << " = " << a*b << "\n";
	//test for whether denominator is 0
	if (b!=0) {
		cout << a << " / " << b << " = " << a/(double)b << "\n";
	}
	else {
		cout << a << " / " << b << " = undefined" << "\n";
	}
}

//solves single variable linear equation
void equation() {
	//input coefficients of equation
	int a, b;
	cout << "Enter values for Ax + B = 0\n";
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	//display steps to solving
	cout << "\n" << a << "x + " << b << " = 0\n";
	cout << a << "x = " << -b << "\n";
	cout << "x = " << -b << "/" << a << "\n";
	//check for whether a solution exists
	if (a!=0) {
		cout << "x = " << -b/(double)a << "\n";
	}
	else {
		cout << "x = undefined\n";
	}
}

//calculates pay
void paycheque() {
	//input wage and hours worked
	double wage, time, regular, overtime;
	cout << "Enter an hourly wage: $";
	cin >> wage;
	cout << "Enter the number of hours worked: ";
	cin >> time;
	//calculate regular and overtime pay
	if (time<40) {
		regular = time*wage;
		overtime = 0;
	}
	else {
		regular = 40*wage;
		overtime = (time-40)*wage*1.5;
	}
	//display pay
	cout << "\nRegular pay: $" << regular << "\n";
	cout << "Overtime pay: $" << overtime << "\n";
	cout << "Total pay: $" << overtime+regular << "\n";
}

//system for ordering pizza
void pizza() {
	//input number of pizzas of each size
	int total, small, medium, large, i;
	small = 0;
	medium = 0;
	large = 0;
	cout << "How many pizzas? ";
	cin >> total;
	cout << "For each pizza, enter its size, S, M, or L.\n";
	//repeatedly prompt for pizza size until all pizzas have been assigned sizes
	for (i = 0; i<total; i++) {
		char choice;
		cin >> choice;
		if (choice=='S') {
			small++;
		}
		else if (choice=='M') {
			medium++;
		}
		else if (choice=='L') {
			large++;
		}
		//display error statement if a size is not valid
		else {
			cout << "Invalid size.\n";
			i--;
		}
	}
	//display cost
	cout << "\nNumber of small pizzas ($6.99 per pizza): " << small << "\n";
	cout << "Number of medium pizzas ($8.99 per pizza): " << medium << "\n";
	cout << "Number of large pizzas ($10.99 per pizza): " << large << "\n";
	cout << "Total cost: $" << small*6.99+medium*8.99+large*10.99 << "\n";
}

//sorts three integers
void sort() {
	//input three integers
	int a, b, c;
	cout << "Enter three integers: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "\nIn order, the integers are: ";
	//sorts integers
	if (a>=b) {
		if (a>=c) {
			if (b>=c) {
				cout << a << ", " << b << ", " << c << "\n";
			}
			else {
				cout << a << ", " << c << ", " << b << "\n";
			}
		}
		else {
			cout << c << ", " << a << ", " << b << "\n";
		}
	}
	else {
		if (a>=c) {
			cout << b << ", " << a << ", " << c << "\n";
		}
		else {
			if (b>=c) {
				cout << b << ", " << c << ", " << a << "\n";
			}
			else {
				cout << c << ", " << b << ", " << a << "\n";
			}
		}
	}
}

//main menu
int main(){
	while (true) {
		//input choice of program
		int choice;
		cout << "Enter a number to select a program: \n";
		cout << "1 - Arithmetic\n";
		cout << "2 - Equation\n";
		cout << "3 - Paycheque\n";
		cout << "4 - Pizza\n";
		cout << "5 - Sort\n";
		cin >> choice;
		system("CLS");
		if (choice==1) {
			arithmetic();
		}
		else if (choice==2) {
			equation();	
		}
		else if (choice==3) {
			paycheque();
		}
		else if (choice==4) {
			pizza();
		}
		else if (choice==5) {
			sort();
		}
		//return to menu
		cout << "\nPress enter to return to home screen.";
		getch();
		system("CLS");
	}
	return 0;
}
