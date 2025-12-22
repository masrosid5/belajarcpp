// memori_dinamis.cpp
// program untuk menunjukkan penggunaan operator new dan delete di cpp

#include <iostream>

using namespace std;

int main(){
    int* ptrData = new int;
    *ptrData = 42;

    cout << "Nilai yang ditunjuk oleh pointer adalah " << *ptrData << " yang ada di alamat: " << ptrData << endl;

    delete ptrData;
    ptrData = nullptr;
    return 0;
}
