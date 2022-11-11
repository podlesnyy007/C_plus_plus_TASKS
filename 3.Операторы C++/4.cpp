#include <iostream>
using namespace std;

int main()
{
	int k;
	for (int i = 1; i <= 5; i++){
		k = i;
		while (k > 0) {
			cout << k << "\t";
			k--;
		}
		cout << endl;
	}
}
