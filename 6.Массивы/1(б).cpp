/*
Дана последовательность целых чисел. Посчитать среднее арифметическое отрицательных элементов. Использовать двумерный массив.
*/

/*
Ввод с клавиатуры:
3 3
-1 3 2
0 -5 -7
10 -2 5
Ответ: -3.75
*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int a[10][10];
    int x, y, k = 0;
    float s = 0;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
            if (a[i][j] < 0) {
                s += a[i][j];
                ++k;
            }
        }
    }
    if (k != 0)
        cout << s/k;
    else
        cout << "Отрицательный чисел в последовательности нет";
}
