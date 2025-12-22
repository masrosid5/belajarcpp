// Solusi dari masalah nomor 2 pada tlx.toki.or.id
// 
/*
Deskripsi
Kali ini Pak Dengklek bermain lagi dengan bebek-bebeknya menggunakan matriks. Pak Dengklek memberikan bebek-bebeknya sebuah matriks berukuran N kali M lalu sejumlah operasi rotasi dan refleksi. Tugas bebek-bebek adalah melakukan operasi rotasi dan refleksi tersebut terhadap matriks yang diberikan. Merasa bosan dengan permainan ini, para bebek meminta bantuan Anda untuk membuatkan sebuah program yang dapat mencetak kembali matriks yang diberikan Pak Dengklek setelah melalui serangkaian operasi rotasi dan refleksi tersebut.

Format Masukan
Baris pertama berisi 3 buah bilangan bulat, N dan M (1 ≤ N, M ≤ 100) yang menyatakan banyaknya baris dan kolom pada matriks, serta X (1 ≤ X ≤ 100) yang menyatakan banyaknya operasi yang dilakukan. N baris berikutnya berisi masing-masing M elemen matriks. Setiap elemen adalah bilangan bulat dari 1 sampai 100, inklusif. X baris berikutnya, masing-masing berisi sebuah operasi matriks, antara lain:

_, merefleksikan matriks berdasarkan garis horizontal
|, merefleksikan matriks berdasarkan garis vertikal
90, merotasikan matriks 90 derajat searah jarum jam
180, merotasikan matriks 180 derajat searah jarum jam
270, merotasikan matriks 270 derajat searah jarum jam
Format Keluaran
Matriks yang diberikan pada masukan setelah melalui rangkaian operasi refleksi dan rotasi.

Contoh Masukan 1
3 3 2
1 2 3
4 5 6
7 8 9
_
270
Contoh Keluaran 1
9 6 3
8 5 2
7 4 1
Contoh Masukan 2
3 3 2
1 2 3
4 5 6
7 8 9
|
90
Contoh Keluaran 2
9 6 3
8 5 2
7 4 1
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int matriks[MAX_SIZE][MAX_SIZE];
int temp[MAX_SIZE][MAX_SIZE];
int N, M, X, newN, newM;
char op[5];

void print();
void refleksi_h();
void refleksi_v();
void rotasi90();

int main(){
    
    scanf("%d %d %d", &N, &M, &X);
    
    
    for (int i=0; i < N; i++) {
        for (int j = 0; j < M; j++) scanf("%d", &matriks[i][j]);
    }
    int op_ctr = 0;
    while (op_ctr < X){
        scanf("%s", op);
        if (strcmp(op, "_") == 0) {
            refleksi_h();
        }
        else if (strcmp(op, "|") == 0) {
            refleksi_v();
        }
        else if (strcmp(op,"90") == 0) {
            rotasi90();
        }
        else if (strcmp(op,"180") == 0) {
            rotasi90();
            rotasi90();
        }
        else if (strcmp(op,"270") == 0) {
            rotasi90();
            rotasi90();
            rotasi90();
        }

        
        op_ctr++;
    }
    

    print();

    return 0;
}

void print(){
    int i,j;
    for (i=0; i < N; i++) {
        for (j = 0; j < M; j++) printf("%d ", matriks[i][j]);
        printf("\n");
    }
}

void refleksi_h(){
    for (int i = 0; i < N/2; i++){
        for(int j = 0; j< M; j++){
            int value = matriks[i][j];
            matriks[i][j] = matriks[N-1-i][j];
            matriks[N-1-i][j] = value;
        }
    }
}

void refleksi_v(){
    for (int i = 0; i < N; i++){
        for(int j = 0; j< M/2; j++){
            int value = matriks[i][j];
            matriks[i][j] = matriks[i][M-1-j];
            matriks[i][M-1-j] = value;
        }
    }
}

void transpose(){
    newM = N;
    newN = M;
    for (int i = 0; i < newN; i++){
        for (int j = 0; j < newM; j++){
            temp[i][j] = matriks[j][i];
        }
    }
    M = newM;
    N = newN;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) matriks[i][j] = temp[i][j];
    }
    
}

void rotasi90(){
    transpose();
    refleksi_v();
}

