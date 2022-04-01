#include <iostream>
using namespace std;


// 1. А - число, у которого нужно подсчитать кол-во единиц в двоичном представлении
// 2. В - счетчик единиц
// 3. В = 0(обнулить счетчик)
// 4. Пока а не равно нулю, выполняем действия 5, 6
// 5. Если А % 2 = 1, то В = В + 1(Увеличиваем счетчик единиц, если в младшем разряде единица)
// 6. А = А / 2(Переходим к анализу следующего разряда)
// 7. Ввести результат(В)

int main() {
    int num = 33554431;
    int mod = 0;

    while (num > 0) {
        mod = mod + (num & 1);
        num = num >> 1;
    }

    printf("%d", mod);
}
