#include <iostream>
#include <string>

using namespace std;

// Hash table
struct HashTable {
    string username, password;
} dataAkun[26];

// hash function
int hashFunction(string password){
    char hurufPertama = password[0];
    return tolower(password[0]) - 97;
}
bool cekDaftar(string username, string password){
    int index = hashFunction(password);

    // cek indeks masih kosong atau udah ditempati
    if (dataAkun[index].username != ""  && dataAkun[index].password != ""){
        cout << "User sudah ada" << endl;
        return false;
    }
    else {
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        return true;
    }
    return false;
}
void viewDaftar(){
    string username, password;
    cout << " == MENU DAFTAR == " << endl;
    cout << "Masukkan usernama & password" << endl;
    cout << "Isi username Anda: "; cin >> username;
    cout << "Isi username Anda: "; cin >> password;
    cout << "Username: " << username << " & password: " << password << endl;

    if (cekDaftar(username, password)){
        cout << "Akun berhasil terdaftar" << endl;
    }
    else {
        cout << "Akun gagal terdaftar" << endl;
    }
}

void printDataAkun(){
    cout << "Data Akun: " << endl;
    cout << "|Index \t - Username \t - Password|" << endl;
    for (int i = 0; i < 26; i++){
        cout << "|" << (i+1) << "\t - " ;
        cout << (dataAkun[i].username != "" ? dataAkun[i].username : "kosong ") << " \t - " << (dataAkun[i].password != "" ? dataAkun[i].password : "kosong ");
        cout << "|" << endl;
    }
}
void welcome(){
    while (true){
        string pilihan;
        cout << " == Program Login Sederhana Dengan HASHING == " << endl;
        cout << "Menu Pilihan: " << endl;
        cout << "1. Daftar" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu [1/2/3]: ";
        cin >> pilihan;
        if (pilihan == "1"){
            viewDaftar();
        }
        else if (pilihan == "2") {
            cout << "Anda berada di menu login." << endl;
        }
        else if (pilihan == "3") {
            cout << "Terima kasih sudah menggunakan aplikasi login sederhana" << endl;
            break;
        }
        else {
            cout << "Pilihan tidak tersedia!" << endl;
        }
    }
}

int main(){
    welcome();
    printDataAkun();

    return 0;
}
