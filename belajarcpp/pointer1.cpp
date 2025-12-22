// Operator & dan *
#include <iostream>

using namespace std;

int main(){
	int p{7};
	int* pPtr = &p;
	
	cout << "The address of p is: " << &p << endl;
	cout << "The value of pPtr is: " << pPtr << endl;
	
	cout << "The value of p is: " << p << endl;
	cout << "The value of *pPtr: " << *pPtr << endl;
	
	return 0;
}
