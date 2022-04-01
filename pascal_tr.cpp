#include <iostream>
#include <math.h>
using namespace std;

long double fack(int n) {
    long double x;
    x = 1;
    for (int i=1; i<=n; i++) {
        x *= i;
    };

    return x;
}

int main() {
    int k, j, c;
    cin >> k;
    cout << "1" << "\n";

    for (j = 1;j <= k;j++) {
        for (c = 0; c <= j; c++) {
            cout << (fack(j) / (fack(c) * fack(j - c))) << " ";
        };
    cout << "\n";
    };

return 0;
}