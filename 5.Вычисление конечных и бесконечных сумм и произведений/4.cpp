/*
Вводимые значения
0.1
0.9
0.1
0.00001
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float fan(float x, float e, int& n) {
    float s = 0, a = 1;  // начальное значение суммы и первое слагаемое
    n = 0;  // количество просуммированных слагаемых
    for (int i = 2; fabs(a) >= e; i++) {
        s += a;
        a *= (pow(-1, i) * x) / ((i - 1) * (i + 2));
        n++; //Увеличиваем количество просуммированных слагаемых
    }
    return s;
}

int main()
{
    float a, b, e, x, h, f; //a и b - отрезок; h - шаг
    int i, n;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "h = "; cin >> h;
    cout << "e = "; cin >> e;
    cout << setprecision(6);
    cout << "i\t\tx\t\tf(x)\t\tn\n";
    for (x = a, i = 1; x <= b; x += h, i++) {
        f = fan(x, e, n);
        cout << i << "\t\t" << x << "\t\t" << f << "\t\t" << n << endl;
    }
}
