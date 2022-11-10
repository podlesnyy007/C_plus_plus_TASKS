#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	int x;
	cin >> x;
	switch (x) {
	case 6:
		cout << "шестерка";
		break;
	case 7:
		cout << "семерка";
		break;
	case 8:
		cout << "восьмерка";
		break;
	case 9:
		cout << "девятка";
		break;
	case 10:
		cout << "десятка";
		break;
	case 11:
		cout << "валет";
		break;
	case 12:
		cout << "дама";
		break;
	case 13:
		cout << "король";
		break;
	case 14:
		cout << "туз";
		break;
	}
}
