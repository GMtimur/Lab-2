#include <iostream>
#include <limits>
#include "queue.h"

using namespace std;

/// <summary>
/// Вставляет число 1 перед каждым отрицательным числом в очереди.
/// </summary>
/// <param name="queue">Очередь, в которую нужно вставить элементы.</param>
void insertBeforeNegatives(Queue<int>& queue) 
{
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; i++) 
    {
        int temp_num = queue.unqueue();
        if (temp_num < 0) 
        {
            queue.queue(1);
        } 
        queue.queue(temp_num);
    }
}

/// <summary>
/// Удаляет все отрицательные числа из очереди.
/// </summary>
/// <param name="queue">Очередь, из которой нужно удалить элементы.</param>
void removeNegatives(Queue<int>& queue) 
{
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; i++) 
    {
        int temp_num = queue.unqueue();
        if (temp_num >= 0) 
        {
            queue.queue(temp_num);
        }
    }
}

/// <summary>
/// Подсчитывает количество вхождений определенного числа в очереди.
/// </summary>
/// <param name="queue">Очередь, в которой нужно подсчитать вхождения.</param>
/// <param name="value">Число, количество вхождений которого нужно подсчитать.</param>
/// <returns>Количество вхождений числа в очереди.</returns>
int countOccurrences(Queue<int>& queue, int value) 
{
    int counter = 0;
    for (int i = 0; i < queue.count(); i++) 
    {
        int temp_num = queue.unqueue();
        if (temp_num == value) 
        {
            counter++;
        }
        queue.queue(temp_num);
    }
    return counter;
}

void displayMenu() 
{
    cout << "1. Добавить элемент в очередь\n";
    cout << "2. Извлечь элемент из очереди\n";
    cout << "3. Показать количество элементов в очереди\n";
    cout << "4. Очистить очередь\n";
    cout << "5. Вставить 1 перед каждым отрицательным числом\n";
    cout << "6. Удалить все отрицательные числа\n";
    cout << "7. Подсчитать количество вхождений числа\n";
    cout << "8. Выйти\n";
    cout << "Выберите действие: ";
}

int main() 
{
    Queue<int> queue;
    int choice;
    while (true) 
    {
        displayMenu();
        while (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите число от 1 до 8.\n";
            displayMenu();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) 
        {
            case 1: 
            {
                int num;
                cout << "Введите число: ";
                cin >> num;
                queue.queue(num);
                cout << "Элемент добавлен." << endl;
                break;
            }
            case 2: 
            {
                try 
                {
                    int item = queue.unqueue();
                    cout << "Извлеченный элемент: " << item << endl;
                } 
                catch (const out_of_range& e) 
                {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: 
            {
                cout << "Количество элементов в очереди: " << queue.count() << endl;
                break;
            }
            case 4: 
            {
                queue.clear();
                cout << "Очередь очищена." << endl;
                break;
            }
            case 5: 
            {
                if(queue.count() == 0)
                {
                    cout << "Очередь была пуста" << endl;
                }
                else
                {
                    insertBeforeNegatives(queue);
                    cout << "Вставка выполнена." << endl;
                }
                break;
            }
            case 6:
            {
                if(queue.count() == 0)
                {
                    cout << "Очередь была пуста" << endl;
                }
                else
                {
                    removeNegatives(queue);
                    cout << "Отрицательные числа удалены." << endl;
                }
                break;
            }
            case 7:
            {
                int value;
                cout << "Введите число для подсчета: ";
                cin >> value;
                int occurrences = countOccurrences(queue, value);
                cout << "Число " << value << " встречается " << occurrences << " раз(а)." << endl;
                break;
            }
            case 8: 
            {
                return 0;
            }
            default: 
            {
                cout << "Неверный выбор." << endl;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}