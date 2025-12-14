#include "bwt.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace bwt {
    void shiftString(std::string& str) {
        if (str.empty()) {
            return;  // Если строка пустая
        }

        std::string temp = str.substr(str.length() - 1);  // всё кроме первого элемента
        str.erase(str.length() - 1);  // удаляем из строки всё кроме первого символа
        str.insert(0, temp);  // Вставляем удалённое в начало
    }

    void encode(const string& s, string& buf, int& index)
    {
        vector<string> shifts(s.length());  // Таблица сдвигов
        string cur = s; // Текущая обрабатываемая строка

        // Заполняем таблицу сдвигов
        for(int i = 0; i != (int)s.length(); i++)
        {
            shifts[i] = cur;  // Добавляем сдвиг
            shiftString(cur); // Сдвигаем строку
        }

        // Сортируем таблицу сдвигов
        sort(shifts.begin(), shifts.end());

        // Собираем результат и ищем индекс
        for(int i = 0; i != (int)s.length(); i++)
        {
            if (shifts[i] == s) {
                index = i; // Индекс исходного значения
            }
            // Добавляем к результату последний символ каждой строки в таблице сдвигов
            buf = buf + shifts[i].back();
        }
    }

    void decode(const string& s, string& buf, int& index) {
        vector<string> shifts(s.length());  // Таблица сдвигов

        for(int i = 0; i != (int)s.length(); i++)
        {
            for(int j = 0; j != (int)s.length(); j++)
            {
                // вставляем в начало строки shifts[j] символ s[j]
                shifts[j].insert(0, std::string(1, s[j]));
            }
            sort(shifts.begin(), shifts.end()); // сортируем результат
        }

        buf = shifts[index];  // Берём из таблицы сдвигов значение по индексу
    }
}
