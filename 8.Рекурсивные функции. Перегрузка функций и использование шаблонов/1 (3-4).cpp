/*
Разработать функцию, которая для заданного натурального числа N возвращает сумму его делитей. С помощью данной функции
для заданного числа А вывести на экран предшествующее по отношению к нему число, сумма делителей которого равна
сумме делителей числа А.
*/

/*
703
Ответ:559
559
Ответ:343
343
Ответ:159
*/

#include <iostream>
using namespace std;

int f(int n) {
	int sum = 0;
	for (int i = 1; n >= i; i++) {
		sum += i * (n % i == 0);
	}
	return sum;
}

int main()
{
	int a, sum = 0;
	cin >> a;
	int x = f(a);
	for (int i = (a - 1); i > 0; i--) {
		int y = f(i);
		if (x == y) {
			cout << i;
			break;
		}
	}
	setlocale(LC_ALL, "Rus");
	cout << endl << "Проверка" << endl;
	int p, o;
	cin >> p >> o;
	cout << f(p) << " " << f(o);
}
