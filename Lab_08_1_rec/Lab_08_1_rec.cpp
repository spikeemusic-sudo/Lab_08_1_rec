// Lab_08_1_rec.cpp
// Фащевський Богдан
// Лабораторна робота № 8.1
// Варіант 28
// Пошук та заміна символів у літерному рядку

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool IncludeChar(const char* str, char c, int j)
{
    if (str[j] == '\0') // якщо досягнуто кінця рядка str (нуль-термінатора), то символ c не знайдено
        return false; // повертаємо false, оскільки шуканий символ відсутній у рядку
    if (str[j] == c) // якщо поточний символ рядка за індексом j збігається з шуканим символом c
        return true; // повертаємо true, оскільки символ знайдено
    return IncludeChar(str, c, j + 1); // рекурсивний виклик для перевірки наступного символу рядка (індекс j + 1)
}

bool Include(const char* str, int i = 0)
{
    const char* cs = "while"; // вказівник на еталонний рядок з букв, наявність яких перевіряємо
    if (cs[i] == '\0') // якщо пройшли всі букви слова "while" і досягли кінця рядка cs
        return true; // повертаємо true, адже всі букви знайдено у рядку str
    if (IncludeChar(str, cs[i], 0)) // якщо поточна i-та буква з cs присутня у рядку str (пошук починаємо з індексу 0)
        return Include(str, i + 1); // рекурсивно перевіряємо наявність наступної букви (індекс i + 1)
    return false; // якщо поточну букву cs[i] не знайдено, повертаємо false
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] == '\0') // якщо досягнуто кінця вхідного рядка str
    {
        *t = '\0'; // завершуємо результуючий рядок нуль-термінатором
        return dest; // повертаємо вказівник на початок результуючого рядка
    }
    if (str[i] == 'w' && str[i + 1] != '\0' && str[i + 1] == 'h' && // перевірка перших двох символів підрядка на "wh"
        str[i + 2] != '\0' && str[i + 2] == 'i' && // перевірка третього символу на 'i' та перевірка на кінець рядка
        str[i + 3] != '\0' && str[i + 3] == 'l' && // перевірка четвертого символу на 'l' та перевірка на кінець рядка
        str[i + 4] != '\0' && str[i + 4] == 'e') // перевірка п'ятого символу на 'e' та перевірка на кінець рядка
    {
        strcat(t, "**"); // додаємо пару зірочок "**" у поточну позицію вказівника t
        return Change(dest, str, t + 2, i + 5); // рекурсивний крок: зсуваємо t на 2 символи вперед (довжина "**"), а i на 5 символів (довжина "while")
    }
    else
    {
        *t++ = str[i]; // копіюємо поточний символ з str у t та зсуваємо вказівник t на 1 позицію
        *t = '\0'; // дописуємо нуль-термінатор у поточний кінець рядка
        return Change(dest, str, t, i + 1); // рекурсивний крок: переходимо до аналізу наступного символу (i + 1)
    }
}

#ifndef UNIT_TESTING
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str))
        cout << "String contains all letters from 'while'" << endl;
    else
        cout << "String DOES NOT contain all letters from 'while'" << endl;

    char* dest = new char[151];
    dest[0] = '\0';
    char* result = Change(dest, str, dest, 0);

    cout << "Modified string (param) : " << dest << endl;
    cout << "Modified string (result): " << result << endl;

    delete[] dest;
    return 0;
}
#endif