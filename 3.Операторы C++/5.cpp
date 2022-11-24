#include <iostream>
using namespace std;
#include <cmath>

double f(double &x) {
    return ((x + 4) / (pow(x, 2) - 2)) + sqrt(pow(x, 3) - 1);
}

int main()
{
    double x1, x2, s;
    cin >> x1 >> x2 >> s;
    for (x1; x1 <= x2; x1 += s) {
        cout << x1 << "\t" << f(x1) << endl;
    }
}
