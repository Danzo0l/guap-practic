#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int mas[] = { 0x0, 0xd, 0x16, 0x1b };

int counter(int a) {
	int k = 0;
	while (a) {
		k += a & 1;
		a = a >> 1;
	}
	return k;
}

int coder(int m) {
	if (m > 3 || m < 0)
		return -1;
	return mas[m];
}

int canal(int m, int e) {
	return mas[m] ^ e;
}

int decoder(int a) {
	int array[4] = { 0 };
	// шаг 1 - вычисление расстояния между кодовыми словами
	for (int i = 0; i < 4; i++) {
		array[i] = mas[i] ^ a;
	}
	for (int i = 0; i < 4; i++)
		printf("%d ", counter(array[i]));

	// шаг 2 - вычисление минимального расстояния
	printf("\n");
	int min = array[0];
	int min_index = 0;
	for (int i = 0; i < 4; i++) {
		if (array[i] < min) {
			min = array[i];
			min_index = i;
		}
	}
	// шаг 3 - принятие решения
	return min_index;
}

int main() {
	int m = 2; //вход кодера
	printf("m = %d\n", m);
	int a = coder(m); // выход кодера
	printf("a = %d\n", a);
	int e = 0x0;
	printf("e = %d\n", e);
	int b = canal(m, e); // выход канала
	printf("b = %d\n", b);
	int m_out = decoder(b); // выход декодера
	printf("m_out = %d\n", m_out);

	return 0;
}