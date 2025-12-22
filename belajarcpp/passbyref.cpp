#include <iostream>

using namespace std;

void addScore(int* score) {
	*score += 5;
	cout << "score diubah menjadi: " << *score << endl;
}

int main(){
	int score = 0;
	
	cout << "Nilai score sebelum diubah: " << score << endl;
	for (int i =0; i < 5; i++){
		addScore(&score);
	}
	cout << "Nilai score setelah diubah: " << score << endl;
	
	return 0;
}