#include<iostream>
#include<string>
#include <fstream> //класс двунаправленных (входных и выходных) файловых потоков 
using namespace std;

int main() 
{
	ifstream in("f.txt"); //открываем входной поток in и связываем его с файлом f.txt
	ofstream out("g.txt"); 
	string str;
	int i = 1;
	while (getline(in, str)) //считываем значение из потока in в переменную str
		out << str << " " << i++ << endl; //помещаем значение переменной str в поток out
	in.close();
	out.close();
	return 0;
}
