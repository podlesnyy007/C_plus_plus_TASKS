#include <iostream>
using namespace std;

int main()
{
    int n; // n - до какого числа
    float k = -0.5, a = -0.5; // сумма 0 + (-0.5)
                             // a - первый член последовательности
    cout << "n = ";  cin >> n;
    for (int i = 2; i <= n; i++) {
        a *= -0.5;
        k += a;
    }
    cout << k;
}
