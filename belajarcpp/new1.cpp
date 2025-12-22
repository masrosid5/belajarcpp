#include <iostream>
#include <string>

using namespace std;

int main(){
	int numGuests;
	cout << "How many guests? ";
	cin >> numGuests;
	
	// Check for invalid inputs
	if (numGuests <= 0) {
		cout << "Number of guest must be at least 1.\n";
		return 0;
	}
	
	// Create memory space for x guests (an array of atrings)
	string* guests = new string[numGuests];
	
	// ignore the leftover newline character after reading numGuests
	cin.ignore();
	
	// Enter guest names
	for (int i = 0; i < numGuests; i++){
		cout << "Enter name for guest " << (i+1) << ": ";
		getline(cin, guests[i]);
	}
	
	//show all guests
	for (int i = 0; i < numGuests;i++){
		cout << guests[i] << endl;
	}
	
	delete[] guests;
	return 0;
}