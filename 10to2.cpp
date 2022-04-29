#include <iostream>
using namespace std;
                    
                
int count_d(int a) {
    int count = 0;
    while (a > 0) {
        count += a & 1;
        a >>= 1;
    }
    return count;
}

