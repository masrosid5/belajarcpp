// tukarNilai.cpp
// program untuk menukar nilai menggunakan pointer

#include <iostream>

using namespace std;

// menukar nilai yang disimpan pada memori yang ditunjuk poleh ptr1 ke ptr2;
void tukarNilai(int* ptr1, int* ptr2);

int main(){
    int a = 5;
    int b = 3;
    int* aptr = &a;
    int* bptr = &b;

    cout << "Nilai a sekarang: " << a << endl;
    cout << "Nilai b sekarang: " << b << endl;
    cout << "Proses penukaran nilai ..." << endl;
    tukarNilai(aptr, bptr);
    cout << "Proses selesai." << endl;
    cout << "Nilai a setelah ditukar: " << a << endl;
    cout << "Nilai b setelah ditukar: " << b << endl;

    return 0;
}

void tukarNilai(int* ptr1, int* ptr2){
    int cadangan = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = cadangan;
}
