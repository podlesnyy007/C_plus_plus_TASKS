#include <iostream>
using namespace std;
#include <cmath>

float f(float &x) {
    if (x < 0)
        return 0.2 * pow(x, 2) - x - 0.1;
    else if (x > 0 && x != 0.1)
        return pow(x, 2) / (x - 0.1);
    else
        return 0;
}

int main()
{
    float x1, x2, s;
    cin >> x1 >> x2 >> s;
    for (x1; x1 <= x2; x1 += s) {
        cout << x1 << "\t" << f(x1) << endl;
    }
}
