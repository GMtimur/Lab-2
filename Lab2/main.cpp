#include <iostream>
#include <limits>
#include "queue.h"

using namespace std;

/// <summary>
/// Вставляет число 1 перед каждым отрицательным числом в очереди.
/// </summary>
/// <param name="queue">Очередь, в которую нужно вставить элементы.</param>
template <typename T>
void insertBeforeNegatives(Queue<T>& queue) 
{
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; i++) 
    {
        T temp_num = queue.unqueue();
        if (temp_num < 0) 
        {
            queue.queue(1);
            queue.queue(temp_num);
        } 
        else 
        {
            queue.queue(temp_num);
        }
    }
}

/// <summary>
/// Удаляет все отрицательные числа из очереди.
/// </summary>
/// <param name="queue">Очередь, из которой нужно удалить элементы.</param>
template <typename T>
void removeNegatives(Queue<T>& queue) 
{
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; i++) 
    {
        T temp_num = queue.unqueue();
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
template <typename T>
int countOccurrences(Queue<T>& queue, T value) 
{
    int counter = 0;
    int initialCount = queue.count();
    for (int i = 0; i < initialCount; i++) 
    {
        T temp_num = queue.unqueue();
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
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) 
        {
            case 1: 
            {
                int num;
                cout << "Введите число: ";
                cin >> num;
                queue.queue(num);
                cout << "Элемент добавлен.\n";
                break;
            }
            case 2: 
            {
                try 
                {
                    int item = queue.unqueue();
                    cout << "Извлеченный элемент: " << item << "\n";
                } 
                catch (const out_of_range& e) 
                {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 3: 
            {
                cout << "Количество элементов в очереди: " << queue.count() << "\n";
                break;
            }
            case 4: 
            {
                queue.clear();
                cout << "Очередь очищена.\n";
                break;
            }
            case 5: 
            {
                insertBeforeNegatives(queue);
                cout << "Вставка выполнена.\n";
                break;
            }
            case 6:
            {
                removeNegatives(queue);
                cout << "Отрицательные числа удалены.\n";
                break;
            }
            case 7:
            {
                int value;
                cout << "Введите число для подсчета: ";
                cin >> value;
                int occurrences = countOccurrences(queue, value);
                cout << "Число " << value << " встречается " << occurrences << " раз(а).\n";
                break;
            }
            case 8: 
            {
                return 0;
            }
            default: 
            {
                cout << "Неверный выбор.\n";
                break;
            }
        }
        cout << "\n";
    }
    return 0;
}