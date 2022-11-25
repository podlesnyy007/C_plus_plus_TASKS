#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    float b1 = 1, b2 = 5, b;
    int n;
    cout << "n = "; cin >> n;
    cout << b1 << " " << b2 << " ";
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1)
            b = b2 - b1;
        if (i % 2 == 0)
            b = b1 + b2;
        b1 = b2;
        b2 = b;
        cout << b << " ";
    }
}
