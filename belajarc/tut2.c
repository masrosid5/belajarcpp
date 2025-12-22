#include <stdio.h>
#include <stdint.h>

int main(){
	uint32_t a = 0b10110101; // 0xB5
	uint32_t b = 0b11101100; // 0xEC

	// operasi AND &
	uint32_t r;

	r = a & b;
	printf("Hasil dari %X & %X: %X\n", a, b, r);

	r = a | b;
	printf("Hasil dari %X | %X: %X\n", a, b, r);

	r = a ^ b;
	printf("Hasil dari %X ^ %X: %X\n", a, b, r);

	r = ~a;
	printf("Hasil dari ~%X: %X\n", a, r);

	r = a >> 3;
	printf("Hasil dari \%X >> 3: %X\n", a, r);

	r = b << 2;
	printf("Hasil dari \%X << 3: %X\n", b, r);
}
