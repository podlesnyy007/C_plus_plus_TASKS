#include<iostream>
using namespace std;

class Rectangle {
private:
    int a, b; //поля класса Rectangle
    static int count; //статическое поле для подсчета количества экземпляров класса

public:
    Rectangle() : a(0), b(0) { //конструктор без параметров
        count++;
    }

    Rectangle(int a, int b) { //конструктор с параметрами
        this->a = a;
        this->b = b;
        count++;
    }

    void printInfo() { //функция для вывода информации о прямоугольнике
        cout << "Длина: " << a << endl;
        cout << "Ширина: " << b << endl;
    }

    int getPerimeter() { //функция для расчета периметра прямоугольника
        return 2 * (a + b);
    }

    int getArea() { //функция для расчета площади прямоугольника
        return a * b;
    }

    void setSides(int a, int b) { //функци для установки длин сторон прямоугольника
        this->a = a;
        this->b = b;
    }

    bool isSquare() { //функция для проверки, является ли данный прямоугольник квадратом
        return a == b;
    }

    Rectangle operator++() { //перегрузка операции ++
        return Rectangle(++a, ++b);
    }

    Rectangle operator--() { //перегрузка операции --
        return Rectangle(--a, --b);
    }

    Rectangle operator*(int scalar) { //перегрузка операции *
        a *= scalar; //Методы каждого объекта имеют доступ к указателю this, который ссылается на сам объект, из которого эти методы были вызваны
        b *= scalar;
        return *this; //возвращение текущего объекта из метода по ссылке с использованием этого указателя
    }

    static int getCount() { //статическая функция для получения количества экземпляров класса
        return count;
    }
};

int Rectangle::count = 0; //инициализация статического поля

int main() {
    setlocale(LC_ALL, "Rus");
    Rectangle r1; //создание объекта с помощью конструктора без параметров
    Rectangle r2(3, 4); //создание объекта с помощью конструктора с параметрами

    r1.printInfo(); //вызов функции для вывода информации о прямоугольнике
    cout << "Периметр: " << r1.getPerimeter() << endl;
    cout << "Площадь: " << r1.getArea() << endl;
    r1.setSides(5, 5); //вызов функции для установки длин сторон прямоугольника
    cout << "Является ли квадратом: " << r1.isSquare() << endl;

    r1.printInfo();
    cout << "Периметр: " << r2.getPerimeter() << endl;
    cout << "Площадь: " << r2.getArea() << endl;
    r1.setSides(5, 5);
    cout << "Является ли квадратом: " << r2.isSquare() << endl;

    ++r2; //вызов перегруженной операции ++ для объекта класса
    r2.printInfo();

    r2 = r2 * 2; //вызов перегруженной операции * для объекта класса
    r2.printInfo();

    cout << "Количество экземпляров: " << Rectangle::getCount() << endl;
}
