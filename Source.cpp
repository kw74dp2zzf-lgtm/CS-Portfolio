#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

// Display menu
void DisplayMenu() {

	cout << "\n=========================" << endl;
	cout << " Corner Grocer Menu" << endl;
	cout << "==========================" << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Display frequency list" << endl;
	cout << "3. Display histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter choice: ";
}

int main() {

	GroceryTracker tracker;

	tracker.LoadData("CaS210_Project_Three_Input_File.txt");

	tracker.CreatBackupFile("frequency.dat");

	int choice = 0;

	while (choice != 4) {

		DisplayMenu();

		while (!(cin >> choice)) {
			cout << "Invalid input. Enter a number 1-4: ";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (choice) {

		case 1: {
			string item;

			cout << "Enter item name; ";
			cin >> item;

			cout << item << " Purchased "
				<< tracker.GetItemFrequency(item)
				<< " time(s)." << endl;

			break;
		}

		case 2:
			tracker.PrintALLFrequencies();
			break;

		case 3:
			tracker.PrintHistogram();
			break;

		case 4:
			cout << "Program exiting..." << endl;
		}
	}

	return 0;
}