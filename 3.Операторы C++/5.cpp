#include <iostream>
using namespace std;

int main()
{
	double a, b, h;
	cin >> a >> b >> h;
	for (a; a <= b; a += h) {
		cout << f(a);
	}
}

double f(double x) {
	return (x + 4) / (pow(x, 2) - 2) + sqrt(pow(x, 3) - 1);
}
