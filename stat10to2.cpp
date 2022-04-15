#include <iostream>

int count_stat(int k) {
    
    int arr[k*2+3];

    for (int i=0; i<k*2+2; i++) {
        int count = 0;
        int a = i;
        while (a > 0) {
            count += a & 1;
            a >>= 1;
        }
        arr[i] = count;
        std::cout << count << ", ";
    }
    return 0;
}

int main() {
    int kk;
    std::cin >> kk;
    int gg = count_stat(kk);
}
