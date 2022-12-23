/*
В двумерном массиве, элементы которого целые числа, вставить новую строку после всех строк, в которых нет ни одного четного элемента.
*/

/*
n = 5
m = 5
2 4 4 6 8
2 4 4 6 8
1 3 5 7 9
1 3 5 7 9
1 3 5 7 9
Строка, которая будет вставлена: 0 0 0 0 0
Ответ:
2 4 4 6 8
2 4 4 6 8
1 3 5 7 9
0 0 0 0 0
1 3 5 7 9
0 0 0 0 0
1 3 5 7 9
0 0 0 0 0
*/

#include <iostream>
using namespace std;

int** f(int& n, int& m) {
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    int** mas = new int* [2 * n]; //Увеличиваем кол-во строк в массиве
    for (int i = 0; i < n; i++)
        mas[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mas[i][j];
    return mas;
}

int main() 
{
    int n, m;
    int** a = f(n, m);
    setlocale(LC_ALL, "Rus");
    cout << "Строка, которая будет вставлена: ";
    int* b = new int[m];
    for (int i = 0; i < m; i++) //Создали новый массив строки, который будем вставлять
        cin >> b[i];
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        int h = 0; //k - проверяем кол-во четных элементов в строке
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] % 2 == 0)
                h++;
        }
        if (h == 0) {
            for (int k = n; k > i; k--) //Сдвигаем строку, где в предыдущей строке не было четных элементов
                a[k + 1] = a[k];
            n++; //увеличиваем размер строк в массиве
            a[i + 1] = new int[m]; // Выделяем память под новую строку массива
            for (int t = 0; t < m; t++)
                a[i + 1][t] = b[t];
        }
    }
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    delete[] b;
    return 0;
}
