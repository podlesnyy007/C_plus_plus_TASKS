/*
Дана последовательность целых чисел. Посчитать среднее арифметическое отрицательных элементов
*/

/*
Ввод с клавиатуры:
10
-5 3 4 -2 10 -1 0 3 100 -10
Ответ: -4.5
*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int a[20];
    int n, k = 0;
    float s = 0;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            s += a[i];
            ++k;
        }
    }
    if (k != 0)
        cout << s/k;
    else
        cout << "Отрицательный чисел в последовательности нет";
}
