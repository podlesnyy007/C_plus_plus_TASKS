#include <iostream>
using namespace std;

int main() 
{
    int n; // до какого числа
    float k = 0; // сумма
    cin >> n;
    for (int i = 1; i <= n; i++) {
        k += pow((-1), i) / pow(2, i);
    }
    cout << k;
}
