/*
Вычислить A*X, где A - это двумерная матрица, X - вектор
*/

/*
1)1 2 0    2)3
  -1 3 -2    4
  -3 6 7     5
Ответ:11
      -1
      50
*/

#include <iostream>
using namespace std;

int** f(int& n, int& m) { //Функция создает и заполняет двумерный масссив
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    int** mas = new int* [n]; //Объявили двумерный динамический массив
    for (int i = 0; i < n; i++)
        mas[i] = new int[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    return mas;
}

int main()
{
    int n, m;
    int** a = f(n, m); //Вызываем функцию
    int* b = new int[m]; //Создаем массив b
    for (int i = 0; i < m; i++) //Кол-во столбцов матрицы a
        cin >> b[i]; //должно совпадать к кол-вом строк матрицы b
    int* c = new int [n];//Создаем новую матрицу размерностью n на 1    
    for (int i = 0; i < n; i++) {
        c[i] = 0;
        for (int j = 0; j < m; j++) {
            c[i] += a[i][j] * b[j]; //Умножаем строку на столбец
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i] << endl;
    }
    for (int i = 0; i < n; i++) //Освобождение памяти
        delete[] a[i];
    delete[] a;
    delete[] b;
    return 0;
}
