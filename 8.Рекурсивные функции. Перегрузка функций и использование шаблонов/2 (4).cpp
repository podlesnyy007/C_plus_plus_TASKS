/*
Разработать рекурсивную функцию, возращающую значение для нахождения наибольшего общего делителя методом Евклида
*/

#include <iostream>
using namespace std;

int f(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		return f(a - b, b);
	else
		return f(a, b - a);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << f(x, y);
}
