// LR8.1_it.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку 
// Варіант 24

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція, яка обчислює кількість груп "abc" у рядку str
int Count(const char* str)
{
    int k = 0;
    // скануємо рядок до символу кінця рядка
    for (int i = 0; str[i] != 0; i++)
        // && обчислюється зліва направо, тому вихід за межі рядка неможливий
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
            k++;
    return k;
}

// Функція, яка замінює кожну групу "abc" на "**"
// Результат записує в str (параметр) і повертає у вигляді нового рядка
char* Change(char* str)
{
    // нова група "**" коротша за "abc", тому місця у tmp вистачить
    char* tmp = new char[strlen(str) + 1];
    // t - вказівник на місце запису наступного символу в tmp
    char* t = tmp;

    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            // записуємо пару зірочок і пропускаємо три символи "abc"
            *t++ = '*';
            *t++ = '*';
            i += 3;
        }
        else
            // інакше просто копіюємо символ
            *t++ = str[i++];
    }
    // закриваємо новий рядок
    *t = '\0';

    // копіюємо результат у вхідний рядок
    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    // звільняємо пам'ять, виділену у функції Change
    delete[] dest;

    return 0;
}