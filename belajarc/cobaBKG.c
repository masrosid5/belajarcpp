/*
Program ini bertujuan untuk mensimulasikan 
Batu-Kertas-Gunting

Permainan ini membutuhkan dua pemain (untuk program ini, user akan melawan komputer)
Aturan permainannya kurang lebih seperti ini.
1. Jika pemain1 dan pemain2 mengeluarkan 'benda' yang sama, maka permainan seri.
2. Batu lawan kertas, pemenangnya kertas
3. Kertas lawan gunting, pemenangnya gunting
4. Gunting lawan batu, pemenangnya batu
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void welcome();
int game();
int play();
char decide_winner(int computer, int user);
void playgame(int cp);
int jwb_komputer();

int main(){
    welcome();
    int opsi;

    srand(time(NULL));

    int cp;

    opsi = play();
    while (opsi == 1){
        cp = jwb_komputer();
        playgame(cp);
        opsi = play();
    } 
    return 0;
}

void welcome(){
    printf("=========================\n");
    printf("SELAMAT DATANG\n");
    printf("Di Game Batu-Kertas-Gunting\n");
    printf("===========================\n");
}

int jwb_komputer(){
    int cp = rand() % 100;
    if (cp < 33) cp = 1;
    else if(cp < 67) cp = 2;
    else cp = 3;
    return cp;
}

int play(){
    printf("Pilihan\n");
    printf("1. Lanjut\n");
    printf("2. Selesai\n");
    printf("Apa pilihanmu? ");
    int opsi;
    scanf("%d", &opsi);
    
    return opsi;
}

void playgame(int cp){
    
    int jawab = game();
    if( jawab < 1 || jawab > 3) {
        printf("Harap pilih yang benar[1/2/3]\n");
        return;
    }
    const char* benda[] = {"", "Batu", "Kertas", "Gunting"};
    printf("Komputer memilih: %s\n", benda[cp]);
    printf("Kamu memilih: %s\n", benda[jawab]);
    
    char result = decide_winner(cp, jawab);
    if (result == 'U') printf("Kamu menang\n");
    else if (result == 'C') printf("Komputer menang\n");
    else printf("Permainan Seri\n");
    
}
int game(){
    int opsi;
    printf("Pilihan\n");
    printf("1. Batu\n");
    printf("2. Kertas\n");
    printf("3. Gunting\n");
    printf("Apa pilihanmu? ");
    
    if (scanf("%d", &opsi)!=1){
        while (getchar() != '\n'){

        }
        return -1;
    }

    return opsi;
}

char decide_winner(int computer, int user){
    if(computer == user) return 'S';
    else if ((computer == 1 && user == 2) || (computer == 2 && user == 3) || (computer == 3 && user == 1) ) return 'U';
    else return 'C';
}