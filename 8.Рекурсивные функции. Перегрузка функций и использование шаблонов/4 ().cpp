#include <iostream>
using namespace std;
#include <cmath>

float f(float x) {
    if (x < 0)
        return 0.2 * pow(x, 2) - x - 0.1;
    if (x > 0 && x != 0.1)
        return pow(x, 2) / (x - 0.1);
    if (x == 0.1)
        return 0;
}

void f(float x, float& y) {
    if (x < 0)
        y = 0.2 * pow(x, 2) - x - 0.1;
    if (x > 0 && x != 0.1)
        y =  pow(x, 2) / (x - 0.1);
    if (x == 0.1)
        y = 0;
}

int main()
{
    float x1, x2, h, x, y;
    cin >> x1 >> x2 >> h;
    cout << "x\t" << "y" << endl << endl;
    for (x = x1; x <= x2; x += h, cout << endl)
        cout << x << "\t" << f(x);
    cout << endl;
    for (int x = x1; x <= x2; x += h, cout << endl) {
        f(x, y);
        cout << x << "\t" << y;
    }
}
