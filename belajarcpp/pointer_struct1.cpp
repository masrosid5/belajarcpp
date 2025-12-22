#include <iostream>
#include <string>

using namespace std;

int main(){
	struct Weapon {
		string name;
		int attack;
		int guard;
	};
	
	struct Player {
		string name;
		int score;
		int hp;
		Weapon *weapon;
	};
	
	Player player1;
	
	Player* p1 = &player1;
	p1->name = "Petani Kode";
	p1->score = 0;
	p1->hp = 100;
	p1->weapon = new Weapon;
	
	p1->weapon->name = "Katana";
	p1->weapon->attack = 16;
	p1->weapon->guard = 10;
	
	cout << "PLAYER STATUS" << endl;
	cout << "Name: " << p1->name << endl;
	cout << "Score: " << p1->score << endl;
	cout << "HP: "<< p1->hp << endl;
	cout << "Weapon" << endl;
	cout << " Name: " << p1->weapon->name << endl;
	cout << " Attack: " << p1->weapon->attack << endl;
	cout << " Guard: " << p1->weapon->guard << endl;
	
	return 0;
}