#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

using namespace std;

// Constructor
GroceryTracker::GroceryTracker() {
}

// Read input file and count frequencies
void GroceryTracker::LoadData(string fileName) {
	ifstream inputFile(fileName);

	string item;

	while (inputFile >> item) {
		itemFrequency[item]++;
	}
	
	inputFile.close();
}

// Create backup file
void GroceryTracker::CreatBackupFile(string fileName) {
	ofstream outputFile(fileName);

	for (auto item : itemFrequency) {
		outputFile << item.first << " "
			       << item.second << endl;
	}

	outputFile.close();
}

// Return frequency of one item
int GroceryTracker::GetItemFrequency(string item) {
	if (itemFrequency.find(item) != itemFrequency.end()) {
		return itemFrequency[item];
	}
	return 0;

}

// Print all frequencies
void GroceryTracker::PrintALLFrequencies() {
	for (auto item : itemFrequency) {
		cout << item.first << " "
			<< item.second << endl;
	}
}
 
// Print histogram
void GroceryTracker::PrintHistogram() {
	for (auto item : itemFrequency) {

		cout << item.first << " ";

		for (int i = 0; i < item.second; i++) {
			cout << "*";
		}

		cout << endl;
	}
}