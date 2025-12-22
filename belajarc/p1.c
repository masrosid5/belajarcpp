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

