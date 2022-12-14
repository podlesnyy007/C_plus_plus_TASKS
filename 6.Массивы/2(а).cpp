

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, k = 0; // k - количество отрицаьельных элементов
    float s = 0; // s - сумма отрицательных элементов
    cout << "n = "; cin >> n;
    int *mas = new int[n]; // Память выделяется с помощью специальной каманды new
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        if (mas[i] < 0) {
            s += mas[i];
            k++;
        }
    }
    if (k != 0)
        cout << s / k;
    else
        cout << "Отрицательный чисел в последовательности нет";
    delete[] mas;
    return 0;
}
