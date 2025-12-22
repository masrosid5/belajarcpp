// Fig 8.10
// Attempting to modify data through a 
// nonconstant pointer to constant data

#include <iostream>

using namespace std;

void f(const int*);

int main(){
	int y{0};
	
	// Harusnya di sini error karena datanya tidak bisa dimodif
	f(&y);
	
	return 0;
}
	
void f(const int *xPtr){
	*xPtr = 100;
}