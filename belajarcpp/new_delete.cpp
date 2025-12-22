#include <iostream>

using namespace std;

int main(){
	int* ptr = new int;
	*ptr = 35;
	cout << *ptr;
	
	delete ptr;
}