// Fig 8.13
// sizeof operator when used on a built-in array's name
// returns the number of bytes in the built-in array
#include <iostream>

using namespace std;

size_t getSize(double*);

int main(){
	double numbers[20];
	
	cout << "The number of bytes in the array is: " << sizeof(numbers) << endl;
	
	cout << "The number of bytes returned by getSize is: " << getSize(numbers) << endl;
	
	
	
	return 0;
}

size_t getSize(double* ptr) {
	return sizeof(ptr);
}