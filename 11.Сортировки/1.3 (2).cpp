#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//открываем глобальные файловые потоки
ifstream in("input.txt");
ofstream out("output2.txt");

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

//В сортировке вставками начинаем со второго элемента. Проверяем между собой второй элемент с первым и, если надо, меняем местами. 
//Сравниваем следующую пару элементов и проверяем все пары до нее.

//сортировка массива методом вставки

void sort2(mas* a, int n) {
    mas temp;
    int i, j;
    for (int i = 1; i < n; i++) {
        j = i - 1;
        while (a[j].key < a[j - 1].key) {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
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
        sort2(stud, n); //сортируем массив записей
        //выводим отсортированные данные в файл output2.txt
        out << m << endl;
        for (i = 0; i < n; i++)
            stud[i].print();
    }
    in.close();
    out.close();
}
