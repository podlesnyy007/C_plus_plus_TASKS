#include <iostream>
using namespace std;

int main() 
{
    int n;
    float k = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        k += pow((-1), i) / pow(2, i);
    }
    cout << k;
}
