/*
Создать файл, состоящий из n вещественных чисел. Вывести на экран все числа данного файла с нечетными порядковыми номерами, большие заданного числа.
*/

#include <iostream> 
#include <fstream>
using namespace std;

int main() {
	ofstream out("f.dat", ios::binary); 
	double n, h, m;
	cout << "n = "; cin >> n;
	cout << "h = "; cin >> h;
	//записываем данные в двоичный файл
	for (int i = 0; i < n; i++) {
		cin >> m;
		out.write((char*)&m, sizeof(double)); //функция записывает в поток из m столько байт, сколько есть в double
	}
	out.close();
	ifstream in("f.dat", ios::binary); //открываем входной поток для открытия двоичного файла
	while (in.peek() != EOF) { //пока не конец файла
		//читаем файлы из двоичного файла
		in.read((char*)&m, sizeof(double)); //функция считывает из потока из m столько байт, сколько есть в double
		if (m > h)
			cout << m << ' ';
		in.seekg(sizeof(double), ios::cur);
		//смещаем указатель относительно текущей позиции
		//указателя на столько байтов, сколько отводится 
		// для хранения вещественного числа, тем самым 
		// пропускаем одно вещественное число в файле
	}
	in.close();
}
