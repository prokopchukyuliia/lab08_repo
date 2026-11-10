// LR8.1_string.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку 
// Варіант 24

#include <iostream>
#include <string>

using namespace std;

// Функція, яка обчислює кількість груп "abc" у рядку s
int Count(const string s)
{
    int k = 0;
    // pos - позиція, з якої починаємо пошук
    size_t pos = 0;
    // find повертає позицію "abc" або -1, якщо групи більше немає
    while ((pos = s.find("abc", pos)) != -1)
    {
        k++;
        // продовжуємо пошук після знайденої групи
        pos += 3;
    }

    return k;
}

// Функція, яка замінює кожну групу "abc" на "**"
// Змінює рядок s (параметр) і повертає його як результат
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("abc", pos)) != -1)
    {
        // замінюємо три символи "abc" на пару зірочок
        s.replace(pos, 3, "**");
        // продовжуємо пошук після вставлених зірочок
        pos += 2;
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}