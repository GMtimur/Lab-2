#include <iostream>
#include "cycleList.h"

using namespace std;

/// <summary>
/// Вставляет 1 перед каждым отрицательным элементом списка.
/// </summary>
/// <param name="list">Список, в который производится вставка.</param>
void insertBeforeNegatives(CycleList<int>& list)
{
    int count = list.count();
    for (int i = 0; i < count; i++)
    {
        if (list[i] < 0)
        {
            list.insert(i, 1);
            i++;
            count++;
        }
    }
}

/// <summary>
/// Удаляет все отрицательные элементы из списка.
/// </summary>
/// <param name="list">Список, из которого производится удаление.</param>
void removeNegatives(CycleList<int>& list)
{
    int i = 0;
    while (i < list.count()){
        if (list[i] < 0)
        {
            list.removeAt(i);
        }
        else
        {
            i++;
        }
    }
}

/// <summary>
/// Выводит содержимое списка на экран.
/// </summary>
/// <param name="list">Список для вывода.</param>
void printList(CycleList<int>& list)
{
    for (int i = 0; i < list.count(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    CycleList<int> list;
    int choice, value, index;

    while (true)
    {
        cout << "1. Добавить элемент\n";
        cout << "2. Вставить элемент\n";
        cout << "3. Удалить элемент по индексу\n";
        cout << "4. Получить элемент по индексу\n";
        cout << "5. Посчитать количество элементов\n";
        cout << "6. Посчитать количество вхождений значения\n";
        cout << "7. Очистить список\n";
        cout << "8. Вставить 1 перед каждым отрицательным элементом\n";
        cout << "9. Удалить все отрицательные элементы\n";
        cout << "10. Вывести список\n";
        cout << "0. Выйти\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Введите значение: ";
                cin >> value;
                list.add(value);
                break;
            case 2:
                cout << "Введите индекс и значение: ";
                cin >> index >> value;
                list.insert(index, value);
                break;
            case 3:
                cout << "Введите индекс: ";
                cin >> index;
                list.removeAt(index);
                break;
            case 4:
                cout << "Введите индекс: ";
                cin >> index;
                try
                {
                    cout << "Элемент с индексом " << index << ": " << list[index] << endl;
                }
                catch (out_of_range& e)
                {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                cout << "Количество элементов: " << list.count() << endl;
                break;
            case 6:
                cout << "Введите значение: ";
                cin >> value;
                cout << "Количество вхождений " << value << ": " << list.countOccurrences(value) << endl;
                break;
            case 7:
                list.clear();
                cout << "Список очищен.\n";
                break;
            case 8:
                insertBeforeNegatives(list);
                cout << "Вставлены 1 перед отрицательными элементами.\n";
                break;
            case 9:
                removeNegatives(list);
                cout << "Отрицательные элементы удалены.\n";
                break;
            case 10:
                printList(list);
                break;
            case 0:
                return 0;
            default:
                cout << "Неверная опция.\n";
        }
    }

    return 0;
}