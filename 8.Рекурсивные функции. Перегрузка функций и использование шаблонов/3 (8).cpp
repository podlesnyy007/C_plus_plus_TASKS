/*
Разработать рекурсивную функцию для вывода на экран цифр натурального числа в прямом порядке. Применить эту функцию ко всем числам из интервала от A до B.
*/

#include <iostream>
using namespace std;

void f(int n) {
    if (n < 10)
        cout << n << " ";
    else {
        f(n / 10); // Рекурсивный вызов для частного
        cout << n % 10 << " ";
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++, cout << endl) {
        f(i);
    }
}
