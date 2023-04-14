/*
Разработать рекурсивную функцию, которая для заданного натурального числа N возвращает сумму его делитей. С помощью данной функции
для заданного числа А вывести на экран предшествующее по отношению к нему число, сумма делителей которого равна
сумме делителей числа А.
*/

#include <iostream>
using namespace std;

int f(int n, int i = 1, int sum = 0) {
    if (i > n / 2) {
        return sum;
    }
    if (n % i == 0) {
        sum += i;
    }
    return f(n, i + 1, sum);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int a;
    cout << "a= ";
    cin >> a;
    int sum = f(a);
    cout << "Сумма делителей равна " << sum << endl;
    cout << "Предыдущее число с такой же суммой делителей: ";
    for (int i = a - 1; i > 0; i--) {
        if (f(i) == sum) {
            cout << i << endl;
            break;
        }
    }
}
