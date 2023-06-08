#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int main()
{
	ifstream in("input2.txt");
	ofstream out("output2.txt");
	int x, n;
	in >> x;
	list<int> L; //создаем список
	int i = 0;
	in >> n;
	L.push_back(n); // добавление первого элемента в список
	L.push_back(x); // добавление числа x после первого элемента списка
	for (; in >> n;) // цикл считывания остальных элементов списка
		L.push_back(n);                
	L.push_back(x); // добавление числа x после последнего элемента списка                 
	list<int>::iterator iter;  //создается итератор для прохода по списку       
	for (iter = L.begin(); iter != L.end(); iter++) { // цикл вывода всех элементов списка
		out << *iter << " ";
	}//Итератор iter устанавливается на начало списка L с помощью метода begin(). Затем программа выводит все элементы списка L в файл
	in.close();
	out.close();
	return 0;
}

//Данный код имеет временную сложность O(n), где n - количество элементов, которые считываются из файла и добавляются в список L.
//Проход по списку L также имеет линейную временную сложность O(n), потому что каждый элемент списка проходится только один раз.
//Таким образом, итоговая временная сложность программы определяется количеством элементов, которые передаются в список, и составляет O(n).

//Выбор контейнера: список выбран из-за возможности быстрой вставки элементов.
//Выбор списка обоснован тем, что нам нужно эффективно вставить элементы, что делается за O(1) в списке.