#include <iostream>
using namespace std;

//Шаблон ввода двумерного массива
template <typename T>
void input(T** mas, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> mas[i][j];
        }
    }
}

//Шаблон вывода двумерного массива
template<typename T>
void output(T** mas, int a, int b) {
    for (int i = 0; i < a; i++, cout << endl) {
        for (int j = 0; j < b; j++) {
            cout << mas[i][j] << " ";
        }
    }
}

//Шаблон для решения основной задачи
template<typename T>
void perestanovka(T** mas, int a, int b) {
    for (int i = 0; i < b / 2; i++) { //проходимся по столбцам вполовину
        for (int j = 0; j < a; j++) { //проходимся по всем строкам
            T temp = mas[j][i];
            mas[j][i] = mas[j][b - i - 1];
            mas[j][b - i - 1] = temp;
        }
    }
}

int main() {
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    int** mas = new int* [a];
    for (int i = 0; i < a; ++i)
        mas[i] = new int[b];
    input(mas, a, b);
    perestanovka(mas, a, b);
    cout << endl;
    output(mas, a, b);
    for (int i = 0; i < a; i++)
        delete[] mas[i];
    delete[] mas;
    return 0;
}
