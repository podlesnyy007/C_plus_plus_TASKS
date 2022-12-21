/*
Найти такую точку, сумма расстояний от которой до остальных точек множества максимальна. Множество точек задано на плоскости.
*/

/*
Количество точек: 4
Координаты точки 1: 3 4
Координаты точки 2: -2 5
Координаты точки 3: 10 3
Координаты точки 4: -6 0
Ответ: точка 3
*/

#include<iostream>
#include<cmath>
using namespace std;

struct point { //структура для хранения координат точки
	double x, y;
};

double dlina(point a, point b) { //функция, вычисляющая расстояние между двумя точками нп плоскости
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main()
{
	setlocale(LC_ALL, "Rus");
	point a[10];
	int n;
	cout << "Количество точек: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Координаты точки " << i + 1 << ": ";
		cin >> a[i].x >> a[i].y;
	}
	double k = 0;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++)
			if (i != j)
				sum += dlina(a[i], a[j]);
		if (k < sum)
			k = sum;
	}
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++)
			if (i != j)
				sum += dlina(a[i], a[j]);
		if (sum == k) {
			cout << endl << "точка " << i + 1;
			break;
		}
	}
}
