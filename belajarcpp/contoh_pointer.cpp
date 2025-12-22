#include <iostream>

using namespace std;

int main(){
	int score = 50;
	int hp = 100;
	int* ptr_hp = &hp;
	
	cout << "Nama Variabel \t Alamat\t\t Konten" << endl;
	cout << "score \t\t " << &score << "\t " << score << endl;
	cout << "hp \t\t " << &hp << "\t " << hp << endl;
	cout << "*ptr_hp \t " << ptr_hp << "\t " << ptr_hp << endl;
	cout << "*ptr_hp \t " << ptr_hp << "\t " << *ptr_hp << endl;
	
	*ptr_hp = 95;
	cout << "hp \t\t " << &hp << "\t " << hp << endl;
	cout << "*ptr_hp \t " << ptr_hp << "\t " << *ptr_hp << endl;
	
	return 0;
}