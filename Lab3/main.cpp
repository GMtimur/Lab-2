#include <iostream>
#include "cycleList.h"

using namespace std;

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

void removeNegatives(CycleList<int>& list)
{
    int i = 0;
    while (i < list.count())
    {
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

void printList(CycleList<int>& list)
{
    for (int i = 0; i < list.count(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void displayMenu()
{
    cout << "Меню:" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Вставить элемент" << endl;
    cout << "3. Удалить элемент по индексу" << endl;
    cout << "4. Получить элемент по индексу" << endl;
    cout << "5. Размер списка" << endl;
    cout << "6. Количество вхождений значения" << endl;
    cout << "7. Очистить список" << endl;
    cout << "8. Вставить 1 перед отрицательными" << endl;
    cout << "9. Удалить все отрицательные" << endl;
    cout << "10. Вывести список" << endl;
    cout << "0. Выход" << endl;
    cout << "Выбор: ";
}

void handleChoice(int choice, CycleList<int>& list) 
{
    switch (choice)
    {
        case 1:
        {
            cout << "Введите значение: ";
            int value;
            cin >> value;
            list.add(value);
            break;
        }
        case 2:
        {
            cout << "Введите индекс и значение: ";
            int index, value;
            cin >> index >> value;
            list.insert(index, value);
            break;
        }
        case 3:
        {
            cout << "Введите индекс: ";
            int index;
            cin >> index;
            list.removeAt(index);
            break;
        }
        case 4:
        {
            cout << "Введите индекс: ";
            int index;
            cin >> index;
            try 
            {
                cout << "Элемент: " << list[index] << endl;
            } 
            catch (out_of_range& e)
            {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Размер: " << list.count() << endl;
            break;
        }
        case 6: 
        {
            cout << "Введите значение: ";
            int value;
            cin >> value;
            cout << "Вхождений: " << list.countOccurrences(value) << endl;
            break;
        }
        case 7:
        {
            list.clear();
            cout << "Список очищен\n";
            break;
        }
        case 8:
        {
            if (list.count() == 0)
            {
                cout << "Список пуст\n";
            } 
            else
            {
                insertBeforeNegatives(list);
                cout << "Операция выполнена\n";
            }
            break;
        }
        case 9:
        {
            if (list.count() == 0) 
            {
                cout << "Список пуст\n";
            }
            else
            {
                removeNegatives(list);
                cout << "Операция выполнена\n";
            }
            break;
        }
        case 10:
        {
            printList(list);
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            cout << "Неверный выбор\n";
        }
    }
}

int main()
{
    CycleList<int> list;
    
    while (true)
    {
        displayMenu();
        int choice;
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите число\n";
            displayMenu();
        }
        handleChoice(choice, list);
    }

    return 0;
}