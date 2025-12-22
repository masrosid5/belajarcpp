#include <iostream>

using namespace std;

// pass by reference tapi pakai pointer 
void Increment(int* value){
	(*value)++;
}

// kalau yang ini pass by reference beneran

void Increment2(int& value){
	value++;
}

int main(){
	int value = 5;
	
	Increment(&value);
	
	cout << value << endl; //6
	
	Increment2(value);
	cout << value << endl; // 7
	
	return 0;
}