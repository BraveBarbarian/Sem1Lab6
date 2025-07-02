
#include <stdio.h>

int main() {

	int x = 1, y = 1, erg;

	erg = 5 != 6 || 1;
	printf("1. Ergebnis: %d\n", erg);
	erg = x++ || y++;
	printf("2. Ergebnis: %d\n", erg);
	x = 1, y = 1;
	erg = (x--)-(--y);
	printf("3. Ergebnis: %d\n", erg);
	erg = ~52 ^ 52;
	printf("4. Ergebnis: %d\n", erg);
	erg = 1 ? 2 : 3;
	printf("5. Ergebnis: %d\n", erg);
	erg = ~0 == -1 ? -2 : -3;
	printf("6. Ergebnis: %d\n", erg);
	erg = -1 ^ ~0 ? 1 : 2;
	printf("7. Ergebnis: %d\n", erg);

	return 0;
}