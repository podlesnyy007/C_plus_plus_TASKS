#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

ifstream in("input.txt"); //открываем глобальные файловые потоки
ofstream out("output.txt");

struct work {
	string surname, name, patronymic, post;
	int year_of_work, salary, work_experience;
	void show(); //член-функция для вывода информации на экран
	void print(); //член функция для вывода информации в файл
};

void work::show() {
	cout << setw(15) << surname << setw(11) << name << setw(16) << patronymic << setw(20) << post
		<< setw(8) << year_of_work << setw(10) << salary << setw(1) << work_experience << endl;
}
void work::print() {
	out << setw(15) << surname << setw(11) << name << setw(16) << patronymic << setw(20) << post
		<< setw(8) << year_of_work << setw(10) << salary << setw(1) << work_experience << endl;
}

int main()
{
	work worker[20]; //описываем массив структур
	int n = 0, min_zp; //n - номер элемента массива
	if (!in)
		cout << "Ошибка при открытии файла input.txt";
	else
		while (in.peek() != EOF) { //чтение данных из файла
			in >> worker[n].surname;
			in >> worker[n].name;
			in >> worker[n].patronymic;
			in >> worker[n].post;
			in >> worker[n].year_of_work;
			in >> worker[n].salary;
			in >> worker[n].work_experience;
			worker[n].show(); //вывод прочтенных данных на экран через член-функцию
			n++;
		}
	cout << "Введите зарплату минимального уровня: ";
	cin >> min_zp;
	if (!out)
		cout << "Ошибка при открытии файла output.txt";
	else {
		int j = 0;
		for (int i = 0; i < n && i != j; i++)
			if (worker[i].salary < min_zp) {
				for (j = i; j < n - 1; j++) //выполняем сдвиг в массиве на одну позицию вправо
					worker[j] = worker[j + 1];
				n--; //уменьшаем количество сотрудников на 1 после удаления
			}
		for (int i = 0; i < n; i++)//записываем результат в новый файл
			worker[i].print(); //вывод данных в файл через член-функцию структуры 
	}
	in.close();
	out.close();
	return 0;
}
