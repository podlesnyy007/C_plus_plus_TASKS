/*
Дано осмысленное текстовое сообщение. Вывести на экран все слова-палиндромы, содержащиеся в заданном сообщении.
*/

/*
казак построил себе шалаш, но тут пошел потом, на помощь к нему пришли мадам и дед.
Ответ: казак   шалаш   тут     мадам   дед
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() 
{
    string str, slovo;                //size_type как синоним unsigned long, т.е достаточно большой, чтобы содержать размер любой строки
    string::size_type k = 0, pos = 0; //pos - позиция начала слова, k - позиция конца слова
    string razdel = ",.:;!? ";
    cout << "str: ";
    getline(cin, str);
    k = str.find_first_of(razdel, pos); //кол-во символов в слове до символов razdel (ищет первое вхождение символов razdel)
    while (k != string::npos) { //ничего не найдено
        slovo = str.substr(pos, k - pos); //выделение подстроки, которая начинается с позиции pos и содержит k - pos символов
        int h = slovo.length() - 1, n = 0;
        if (k - pos == 1) //убираем слова, состоящие из 1 символа
            n++;
        for (unsigned i = 0; i < h; i++, h--) {
            if (slovo[i] != slovo[h])
                n++;
        }
        if (n == 0)
            cout << slovo << "\t";
        if (ispunct(str[k])) //возвращает true, если знак пунктуации
            pos = k + 2; // пунктуации + пробел
        else
            pos = k + 1; //пробел
        k = str.find_first_of(razdel, pos); //кол-во символов нового слова
    }
}
