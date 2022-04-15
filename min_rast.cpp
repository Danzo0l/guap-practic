#include <iostream>
#include <math.h>
using namespace std;

int arr_len = 5;
int arr[] = {0x1, 0xaa, 0xaf, 0x12, 0x57};

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
    for (i=0; i<arr_len; i++) {
        for (j=i+1; j<arr_len; j++) {
            int buf = hemming(arr[i], arr[j]); 
            if (buf < min) {
                min = buf;
            }
            printf("<%d,%d>", arr[i], arr[j]);
            printf(" %d, ", buf);
            printf("%d, ", count_d(arr[i]));
            printf("%d\n", count_d(arr[j]));

        }
    }

    printf("%d", min);
}

