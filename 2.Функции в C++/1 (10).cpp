#include <iostream>
using namespace std;

void f(int& x) {
	if (x % 2 == 0) {
		x /= 2;
	}
	else {
		x = 0;
	}
}

int main() {
	int x;
	cin >> x;
	f(x);
	cout << x;
}
