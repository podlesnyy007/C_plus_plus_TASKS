#include <iostream>
using namespace std;
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Rus");
	float x, y;
	cin >> x >> y;
	if (fabs(x) < 12 && 0 < y && y < 12 && fabs(x) < y)
		cout << "да";
	else if ((fabs(x) == y) || (fabs(x) < 12 && y == 12))
		cout << "на границе";
	else
		cout << "нет";
}
