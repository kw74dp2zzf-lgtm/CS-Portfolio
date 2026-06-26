/*
*
* Name: Khadije Mohamed Salem
* Date: June 21, 2026
* Course: CS210
*
*/

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
	map<string, int> itemFrequency;

public:
	GroceryTracker();

	void LoadData(string fileaName);
	void CreatBackupFile(string fileName);

	int GetItemFrequency(string item);

	void PrintALLFrequencies();
	void PrintHistogram();
};

#endif