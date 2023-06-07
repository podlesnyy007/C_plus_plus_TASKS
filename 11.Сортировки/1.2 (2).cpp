#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//открываем глобальные файловые потоки
ifstream in("input.txt");
ofstream out("output3.txt");

struct mas {
    string fam, name, secondname;
    int age;
    int ses[5];
    double key; //средняя оценка
    void print();
};

//вывод данных в выходной поток
void mas::print() {
    out << fam << " " << name << " " << secondname << " " << age;
    for (int i = 0; i < 5; i++)
        out << " " << ses[i];
    out << endl << key << endl;
}

//сортировка посредством выбора: ищем наименьшее значение в массиве и ставим его на позицию, откуда начали проход. Потом двигаемся на следующую позицию. Всего таких
//порядков будет n-1, т.к после этого последняя запись также будет стоять на своем месте

//сортировка массива методом выбора

void sort3(mas* a, int n) {
    mas temp;
    int lowkey;
    int lowindex;
    int i, j;
    for (int i = 0; i <= n - 1; i++) {
        lowindex = i;
        lowkey = a[i].key;
        for (j = i + 1; j < n; j++) {
            if (a[j].key < lowkey) {
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        temp = a[i];
        a[i] = a[lowindex];
        a[lowindex] = temp;
    }
}

int main() {
    int n = 0, m, i;
    mas stud[10];
    if (!in)
        cout << "Ошибка при открытии файла input.txt\n";
    else {
        in >> m; //считываем номер группы
        //считываем данные про всех студентов
        while (in.peek() != EOF) {
            in >> stud[n].fam;
            in >> stud[n].name;
            in >> stud[n].secondname;
            in >> stud[n].age;
            //считываем оценки и высчитываем средний балл
            stud[n].key = 0;
            for (i = 0; i < 5; i++) {
                in >> stud[n].ses[i];
                stud[n].key += stud[n].ses[i];
            }
            stud[n].key /= 5;
            n++;
        }
        sort3(stud, n); //сортируем массив записей
        //выводим отсортированные данные в файл output3.txt
        out << m << endl;
        for (i = 0; i < n; i++)
            stud[i].print();
    }
    in.close();
    out.close();
}
