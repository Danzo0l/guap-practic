#include <iostream>
#include <math.h>

int codes[] = {0x0, 0xd, 0x16, 0x1b}; // писать после 0х шестнадцатеричное число

int coder(int a) {
    if (a < 0 || a > 3) return -1;
    return codes[a];
}

int chanel(int vec, int mas) {
    return vec ^ mas;
}

int two(int num) {
    int count = 0;
    for (int i = 0; i < sizeof(num) * 8; i++) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int decoder(int message) {
    int out = 0;
    int par = 1000;
    int ras[4] = {0};
    for (int i=0; i<4; i++) {
        ras[i] = abs(codes[i] - message);
        if (par > ras[i]) {
            out = i;
            par = ras[i];
        }
        printf("<<%d>>", ras[i]);
        
    }
    return out;
}

int main() {
    int m;
    int e;

    std::cin >> m;
    std::cin >> e;

    int a =   coder(m);
    int b = chanel(a, e);

    printf("a=%d = %x\n", m, a);
    printf("b=%d\n", b);
    printf("\ncode=%d\n", decoder(b));

}
    
