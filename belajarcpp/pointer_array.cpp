#include <iostream>

using namespace std;

int main(){
	cout << " ## Program Antrian CS ##" << endl;
	
	char no_antrian[5] = {'A', 'B', 'C', 'D', 'E'};
	
	char* ptr_current = no_antrian;
	
	for (int i = 0; i < 5; i++){
		cout << "Pelanggan dengan nomor antrian " << *ptr_current << " silakan ke loket!" << endl;
		cout << "Saat ini CS sedang melayani: " << *ptr_current << endl;
		cout << "---------- Tekan Enter untuk Next ----------";
		cin.get();
		ptr_current++;
	}
	cout << "Antrian Selesai" << endl;
}