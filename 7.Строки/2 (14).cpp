/*
Даны символ C и строки S, S0. После каждого вхождения символа C в строку S вставить строку S0.
*/

/*
s = hello
s0 = w
c = l
Ответ: helwlwo
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() 
{
    char c;
    string s, s0;
    cout << "s = ";  getline(cin, s);
    cout << "s0 = ";  getline(cin, s0);
    cout << "c = "; cin >> c;
    string res;
    for (unsigned int i = 0; i < s.length(); i++) {
        res += s[i];
        if (s[i] == c)
            res += s0;
    }
    cout << res;
}
