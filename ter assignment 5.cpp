#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//display all members of an array
void display (int* array, int size) {
	int i;
	cout << "The array elements are:\n";
	//loop through all elements
	for (i = 0; i<size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
}

//fill an array with random numbers
int* fill (int size) {
	//create new array pointer
	int* temp = new int [size];
	int i;
	//initialize random seed
	srand (time(NULL));
	//set each element to a random number between 1 and 10 inclusive
	for (i = 0; i<size; i++) {
		temp[i] = rand()%10+1;
	}
	return temp;
}

//calculate average of an array
double average (int* array, int size) {
	int i;
	int sum = 0;
	//find sum of all elements
	for (i = 0; i<size; i++) {
		sum = sum+array[i];
	}
	//find average
	return sum/(size+0.0);
}

//find minimum of an array
int min (int* array, int size) {
	int i;
	int min = INT_MAX;
	//loop through all elements
	for (i = 0; i<size; i++) {
		if (array[i]<min) {
			min = array[i];
		}
	}
	return min;
}

//find maximum of an array
int max (int* array, int size) {
	int i;
	int max = INT_MIN;
	//loop through all elements
	for (i = 0; i<size; i++) {
		if (array[i]>max) {
			max = array[i];
		}
	}
	return max;
}

//search for a given element
int search (int* array, int size, int value) {
	int i;
	//return search position immediately if element is found
	for (i = 0; i<size; i++) {
		if (array[i]==value) {
			return i;
		}
	}
	//in case element is not present
	return -1;
}

//add an item to a given position
int* addItem (int* array, int &size, int pos, int value) {
	//create new array pointer
	int* temp = new int [size+1];
	int i;
	for (i = 0; i<size+1; i++) {
		//keep existing elements
		if (i<pos) {
			temp[i] = array[i];
		}
		//add new element
		else if (i==pos) {
			temp[i] = value;
		}
		//shift all elements after one spot forward
		else {
			temp[i] = array[i-1];
		}
	}
	delete [] array;
	size++;
	return temp;
}

//remove an item from a given position
int* removeItem (int* array, int &size, int pos) {
	//do nothing if array is empty
	if (size!=0) {
		//create new array pointer
		int* temp = new int [size-1];
		int i;
		for (i = 0; i<size-1; i++) {
			//keep existing elements
			if (i<pos) {
				temp[i] = array[i];
			}
			//shift all elements after one spot back
			else {
				temp[i] = array[i+1];
			}
		}
		delete [] array;
		size--;
		return temp;
	}
}

//input elements into an array
int* input (int* array, int &size) {
	delete [] array;
	//create new array pointer
	int* temp = new int [1];
	int value;
	size = 0;
	//stop if user enters -1
	while (value!=-1) {
		//prompt for input
		cout << "Enter array value (enter -1 to quit): ";
		cin >> value;
		//add value
		if (value!=-1) {
			temp = addItem(temp,size,size,value);
		}
	}
	return temp;
}

//main menu
int main(){
	int* array = new int[0];
	int size = 0;
	while (true) {
		//input choice of program
		int choice;
		cout << "Enter a number to select a program: \n";
		cout << "1 - fill\n";
		cout << "2 - input\n";
		cout << "3 - average\n";
		cout << "4 - min\n";
		cout << "5 - max\n";
		cout << "6 - search\n";
		cout << "7 - addItem\n";
		cout << "8 - removeItem\n";
		cout << "Note that to initialize the array, 1 or 2 must be selected first.\n";
		cin >> choice;
		system("CLS");
		if (choice==1) {
			//prompt for size
			cout << "Enter the size of the array: ";
			cin >> size;
			delete [] array;
			//fill and display array
			array = fill(size);
			display(array, size);
		}
		else if (choice==2) {
			//fill and display array
			array = input(array, size);
			display(array, size);
		}
		else if (choice==3) {
			//calculate and display average
			double num = average(array, size);
			cout << "The average is " << num << ".\n";
		}
		else if (choice==4) {
			//find and display minimum
			int num = min(array, size);
			cout << "The minimum is " << num << ".\n";
		}
		else if (choice==5) {
			//find and display maximum
			int num = max(array, size);
			cout << "The maximum is " << num << ".\n";
		}
		else if (choice==6) {
			int value;
			//prompt for value to be searched
			cout << "Enter a value to be searched: ";
			cin >> value;
			//find and display search result
			int pos = search(array, size, value);
			if (pos==-1) {
				cout << "The value is not present in the array.\n";
			}
			else {
				cout << "The value occurs at position " << pos << ".\n";
			}
		}
		else if (choice==7) {
			int pos, value;
			//prompt for position and value to add
			cout << "Enter the position to add the new element: ";
			cin >> pos;
			cout << "Enter the value to be added: ";
			cin >> value;
			//add item and display array
			array = addItem(array, size, pos, value);
			display(array, size);
		}
		else if (choice==8) {
			int pos;
			//prompt for position to remove
			cout << "Enter the position to remove the element: ";
			cin >> pos;
			//remove item and display array
			array = removeItem(array, size, pos);
			display(array, size);
		}
		//return to menu
		cout << "\nPress enter to return to home screen.";
		getch();
		system("CLS");
	}
	return 0;
}
