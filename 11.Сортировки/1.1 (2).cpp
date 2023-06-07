#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//открываем глобальные файловые потоки
ifstream in("input.txt");
ofstream out("output1.txt");

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

//метод "пузырька": начиная проход снизу, сравниваются 2 элемента. Если встречается запись с более "тяжелым" ключом, то эти записи меняются местами.
//При встрече с записью с более "легким" ключом эта запись становится эталоном для сравнения, и все последующие записи сравниваются с этим новым.

//сортировка массива записей из n элементов методом "пузырька"

void sort1(mas* a, int n) {
    mas temp;
    int i, j;
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j].key < a[j - 1].key) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
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
        sort1(stud, n); //сортируем массив записей
        //выводим отсортированные данные в файл output.txt
        out << m << endl;
        for (i = 0; i < n; i++)
            stud[i].print();
    }
    in.close();
    out.close();
}
