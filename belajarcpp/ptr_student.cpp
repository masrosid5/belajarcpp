#include <iostream>

using namespace std;

class Student {
	public:
	
	// constructor initialize Student's age to 12
	Student() : age{12} {};
	
	int getAge(){
		return age;
	}
	
	private:
	int age;
};

int main(){
	Student* p = new Student();
	
	cout << "Umur p adalah " << p->getAge() << endl;
	
	delete p;
	
	return 0;
}