#include <iostream>
using namespace std;

int main() 
{
	int x = 10;
	while (x < 100) {
		if (x % 10 != x / 10)
			cout << x << " ";
		x++;
	}

	cout << endl << endl;
	int y = 10;
	do
		if (y % 10 != y / 10)
			cout << y++ << " ";
		else
			y++;
	while (y <= 99);

	cout << endl << endl;
	for (int i = 10; i < 100; i++) {
		if (i % 10 != i / 10)
			cout << i << " ";
	}
}
