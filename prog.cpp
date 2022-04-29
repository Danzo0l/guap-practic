#include <iostream>
#include <math.h>
using namespace std;

int Weight(int k)
{
    int w[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int count = 0;
    while (k > 0){
        count += w[k & 15];
        k = k >> 4;
    }
    return count;
}

int mind(int* mas, int t)
{
    int min = 10000000;
    int count = 0;
    for (int i = 0; i < t; i++){
        int b = mas[i];
        for (int j = i+1; j < t; j++){
            int r = Weight(b ^ mas[j]);
            if (r < min){
                min = r;
            }
            count++;
        }
    }
    return min;
}


int counter(int a) {//счетчик единиц в числе
    int k = 0;
    while (a) {
        k += a & 1;
        a = a >> 1;
    }
    return k;
}

int dist(int a, int b) {
    return counter(a ^ b);
}

void print(int n, int x){
    int A[x] = {0};
    for (int i = 0; i < x; i++)
    {
        A[i] = n % 2;
        n = (int)n / 2;
    }
    for (int i = x-1; i >= 0; i--) printf("%d", A[i]);
    printf("\n");
}

int main() {
    int n = 7, d = 3, M = 0; // n - степень, d - расстояние, M - количество полученных слов
    int l = (int)pow(2, n); // 2^n
    int t[l] = {0}; // метки
    int A[l] = {0}; // кодовые слова
    int check = 0;

    start:; // переход на след круг
    int H = -1; // временная переменная для просмотра, нашлось ли не задействованное число
    if (check == 0)
    {
        H = 0;
        check = 1;
        goto next;
    }
    for (int k = 0; k < l; k++) // находим ближайшее не просмотренное число
    {
        if (t[k] == 0) // если число не задействовано
        {
            H = k; // если нашлось меняем H, показываем что нашли переменную
            break;
        }
    }
    next:;

    if (H != -1) // если незадействованное число нашлось
    {
        A[M++] = H; // заносим его в массив A
        t[H] = 2; // помечаем меткой '2' слово в массиве меток
    }
    else goto stop; // если не нашлось, то объявляем конец алгоритма

    //шаг 2
    for (int i = 0; i < l; i++) { // исключаем все слова для которых d(a1, ti) < d
        if (t[i] == 0 && dist(A[M-1], i) < d) { // если слово не проверялось и расстояние между выбранным словом и словом < d
            t[i] = 1; // убираем его, ставим метку '1'
        }
        printf("%d ", t[i]); // вывод для просмотра шагов алгоритма
    }
    printf("\n");

    goto start; // переход на следующий шаг (+ проверка)
    stop:;
    printf("\n");
    for (int j = 0; j < M; j++) print(A[j], n); // вывод полученных слов
    printf("M = %d ", M);
    printf("MinD = %d ", mind(A, M));
}