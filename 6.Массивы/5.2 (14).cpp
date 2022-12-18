#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "n = "; cin >> n; //n - количество элементов в массиве
    cout << "k = "; cin >> k; //k - элемент, который нужно вставить
    int m = 2 * n;
    int* a = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int h = a[i];
        while (h > 0) {
            if (h % 10 == k) {
                for (int j = n; j > i; j--)
                    a[j] = a[j - 1];
                a[i] = k;
                n++;
                break;
            }
            h /= 10;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
