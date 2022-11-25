#include <iostream>
using namespace std;
#include <cmath>

void f(double &x) {
    if (x == sqrt(2) || x < 0)
        cout << "функция не определена";
    else
        cout << ((x + 4) / (pow(x, 2) - 2)) + sqrt(pow(x, 3) - 1);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    double x1, x2, s;
    cin >> x1 >> x2 >> s;
    for (x1; x1 <= x2; x1 += s) {
        cout << x1 << "\t";
        f(x1);
        cout << endl;
    }
}
