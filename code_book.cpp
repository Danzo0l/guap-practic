#include <iostream>
#include <math.h>

using namespace std;

int countUnitsWithoutArray(unsigned int number) {
	int w = (number & 1);
	for (int i = 0; i < sizeof(number) * 8; i++) {
		w += ((number >>= 1) & 1);
	}
	return w;
}

int main() {
	int d, n;

    std::cout << "D: ";
    std::cin >> d;
    std::cout << "N: ";
    std::cin >> n;

	int pow_2n = pow(2, n);
	int* A = (int*)malloc(sizeof(int) * pow_2n); // в этом массиве будем формировать списак кодовых слов
	int* X = (int*)calloc(pow_2n, sizeof(int)); // индексы массива соответствуют всем последовательностям длинны n. До начала работы все последовательности свободны.
	int index = 0;

	//первый шаг алгоритма: выбираем 1 свободную последовательность
	for (int i = 0; i < pow_2n; i++) {
		for (int k = 0; k < pow_2n; k++) {
			if (X[k] == 0) {
				A[index++] = k; // i-тому кодовому слову ставим соответствие последовательность k
				break; //Выходим из цикла после найденной свободной последовательности
			}
		}
		X[A[index-1]] = 2; //позиция соответствующая кодовому слову - занята
		//второй шаг алгоритма
		// помечаем все последовательности, которые отстоят от кодового слова на растоянии d-1
		for (int j = 0; j < pow_2n; j++) {
			if (X[j] == 0) {
				// если d(A[i], j) < d , то X[j] = 1
				if (countUnitsWithoutArray(j ^ A[index-1]) < d) {
					X[j] = 1;
				}
			}
		}
	}

	std::cout << "N: " << n << " count: " << index << endl;

	for (int i = 0; i < index; i++) {
		cout << A[i] << " ";
	}

    return 0;
}