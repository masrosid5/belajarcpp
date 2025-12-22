// Fig 8.11
// Attempting to modify a constant pointer to nonconstant data
#include <iostream>

using namespace std;

int main(){
	int x,y;
	
	// ptr is a constant pointer to an integer that can be modified
	// through pointer, but ptr always point to the same memory address
	int* const ptr = &x;
	
	*ptr = 7; // bisa karena data di variabel x bukan const
	
	ptr = &y; // error karena ptr merupakan constant pointer, tidak bisa diganti
	
	return 0;
}
