#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int banyaknya_vokal = 0;
    for (char c : s){
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            banyaknya_vokal++;
        }
    }
    cout << banyaknya_vokal << endl;
}
