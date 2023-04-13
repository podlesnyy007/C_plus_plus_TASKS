/*
Дан текст содержащий цифры. Заменить все нечетные цифры наименьшей цифрой, содержащейся в данном тексте.
*/

#include <iostream> 
#include <string> 
using namespace std;

int main() {
	string str;
	getline(cin, str, '\n'); //вводим строку целиком в переменную str
	char min = str[0]; //первой цифре в строке присваиваем минимальное значение
	//поиск минимума 
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < min) {
			min = str[i];
		}
	}
	//заменяем нечётные минимумом
	for (int i = 0; i < str.length(); i++) {
		if (str[i] % 2 == 1) {
			str[i] = min;
		}
	}
	cout << str;
}
