#include <iostream>
#include <conio.h>

using namespace std;

//add integers
void adding(){
	//input integers
	int sum = 0;
	int temp;
	cout << "Enter first integer (enter 0 to quit): ";
	cin >> temp;
	//check if first input is 0
	if (temp==0) {
		cout << "No integers were entered.\nbye\n";
	}
	else {
		sum = temp;
		//prompt for more inputs while input is not 0
		while (temp!=0) {
			cout << "Enter an integer (or 0 to quit): ";
			cin >> temp;
			sum = sum+temp;
		}
		//display sum
		cout << "Sum of the integers: " << sum;
		cout << "\nbye\n";
	}
}

//miles per gallon program
void mpg(){
	double i, f, g;
	cout << "Miles Per Gallon Program\n";
	//sentinel loop
	do {
		cout << "Initial miles:\n";
		cin >> i;
		//check if i is positive
		if (i>=0) {
			//display calculations
			cout << "Final miles:\n";
			cin >> f;
			cout << "Gallons:\n";
			cin >> g;
			printf ("Miles per Gallon: %.1f \n\n", (f-i)/g);
		}
	} while (i>0);
	cout << "bye\n";
}

//sum integers in range
void range(){
	//prompt for range input
	int low, high;
	int temp = 1;
	int sum1 = 0;
	int sum2 = 0;
	cout << "In-range Adder\n";
	cout << "Low end of range:\n";
	cin >> low;
	cout << "High end of range:\n";
	cin >> high;
	//prompt for input while it is not 0
	while (temp!=0) {
		cout << "Enter data:\n";
		cin >> temp;
		//calculate low and high sum
		if (temp>=low&&temp<=high) {
			sum1 = sum1+temp;
		}
		else {
			sum2 = sum2+temp;
		}
	}
	//display sum
	cout << "Sum of in range values: " << sum1 << "\n";
	cout << "Sum of out of range values: " << sum2 << "\n";
}

//shipping program
void shipping(){
	double w, c;
	//sentinel loop
	do {
		cout << "Weight of Order:\n";
		cin >> w;
		//check if weight is not 0
		if (w>0) {
			//calculate cost
			if (w<10) {
				c = 3;
			}
			else {
				c = 3+0.25*(w-10);
			}
			//display cost
			printf ("Shipping Cost: $%.2f \n\n", c);
		}
	} while (w>0);
	cout << "\nbye\n";
}

//calculate hailstone numbers
void hailstone(){
	int n, max, prev;
	//input starting value
	cout << "Enter initial number: ";
	cin >> n;
	max = n;
	//sentinel loop
	do {
		prev = n;
		cout << n << " ";
		//check if sequence terminates
		if (n==1) {
			cout << "(stop calculation)\n";
		}
		else {
			//operations depend on if number is even or odd
			if (n%2==0) {
				cout << "(even, next value is " << n << "/2)\n";
				n = n/2;
			}
			else {
				cout << "(odd, next value is 3*" << n << "+1)\n";
				n = n*3+1;
				//keep track of maximum (only occurs for odd numbers)
				if (n>max) {
					max = n;
				}
			}
		}
	} while (prev>1);
	//display maximum
	cout << "The maximum number reached was " << max << "\n";
}

//main menu
int main(){
	while (true) {
		//input choice of program
		int choice;
		cout << "Enter a number to select a program: \n";
		cout << "1 - Adding Integers\n";
		cout << "2 - Miles per Gallon\n";
		cout << "3 - In-range Adder\n";
		cout << "4 - Shipping Cost Calculator\n";
		cout << "5 - Hailstone Numbers\n";
		cin >> choice;
		system("CLS");
		if (choice==1) {
			adding();
		}
		else if (choice==2) {
			mpg();	
		}
		else if (choice==3) {
			range();
		}
		else if (choice==4) {
			shipping();
		}
		else if (choice==5) {
			hailstone();
		}
		//return to menu
		cout << "\nPress enter to return to home screen.";
		getch();
		system("CLS");
	}
	return 0;
}
