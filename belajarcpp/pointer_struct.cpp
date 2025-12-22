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
	player1.name = "Petani Kode";
	player1.score = 0;
	player1.hp = 100;
	player1.weapon = new Weapon;
	
	(*player1.weapon).name = "Katana";
	(*player1.weapon).attack = 16;
	(*player1.weapon).guard = 10;
	
	cout << "PLAYER STATUS" << endl;
	cout << "Name: " << player1.name << endl;
	cout << "Score: " << player1.score << endl;
	cout << "HP: "<< player1.hp << endl;
	cout << "Weapon" << endl;
	cout << " Name: " << (*player1.weapon).name << endl;
	cout << " Attack: " << (*player1.weapon).attack << endl;
	cout << " Guard: " << (*player1.weapon).guard << endl;
	
	return 0;
}