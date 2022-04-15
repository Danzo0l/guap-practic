#include <iostream>
#include <math.h>
using namespace std;

int arr_len = 32;
int arr[] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

int reschet(int n) {
    int result = 0;
    for (int i=0; i<n; i++) {
        result += i;
    }
    return result;
}

int count_d(int a) {
    int count = 0;
    while (a > 0) {
        count += a & 1;
        a >>= 1;
    }
    return count;
}

int hemming(int dem1, int dem2) {
    int dist = dem1 ^ dem2;
    
    return count_d(dist);
}

// минимальное  расстояние Хэмминга
int main() {
    int min = 2147483646;
    int i;
    int j;
    int count = 0;
    for (i=0; i<arr_len; i++) {
        for (j=i+1; j<arr_len; j++) {
            int buf = hemming(arr[i], arr[j]); 
            if (buf < min) {
                min = buf;
                
            }
            count++;
            printf("<%d,%d>", arr[i], arr[j]);
            printf(" %d, ", buf);
            printf("%d, ", count_d(arr[i]));
            printf("%d\n", count_d(arr[j]));

        }
    }

    printf("\nmin >>>%d", min);
    printf("\ncount >>>%d", count);
    printf("\ncount >>>%d", reschet(arr_len));


    // расчет по формуле арифметической прогресии от 1 до n-1 , где n - количество элементов в массиве
}

