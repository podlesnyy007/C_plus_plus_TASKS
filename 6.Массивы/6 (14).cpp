#include <iostream>
using namespace std;

int main()
{
    int n, x; //n - размер массива, x - элемент, который нужно вставить
    cout << "n = "; cin >> n;
    cout << "x = "; cin >> x;
    int m = n * 2;
    int* mass = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> mass[i];
    }
    for (int i = n; i >= 0; i--) {
        int temp = 0;
        temp = mass[i];
        while (temp) {
            if (temp % 10 == x) {
                for (int j = m; j > i; j--) {
                    mass[j] = mass[j - 1];
                }
                mass[i] = x;
                n++;
                break;
            }
            temp /= 10;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    system("pause");
    return 0;
}
