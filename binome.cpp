#include <iostream>

using namespace std;

unsigned long long fack(int a) {
    unsigned long long aa = 1;
    for (int i=1; i<a+1; i++) {
        aa *= i;
    }
    return aa;
}

unsigned long long binome(int n, int k) {

    unsigned long long c = fack(n) / (fack(k) * fack(n-k));

    return c;
}

int main() {
     
    int input;

    cout << "\n\x1B[32m>>>\t";
    cin >> input;
    cout << "\033[0m\n ";

    for (int i=1; i<input; i++) {
        unsigned long long c = fack(input) / (fack(i) * fack(input-i));
        printf("%lld ", c);
    }

    cout << "1\n";



    return 0;
}