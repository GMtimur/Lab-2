#include <iostream>
#include <limits>
#include "queue.h"

using namespace std;

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
                queue.insertBeforeNegatives();
                cout << "Вставка выполнена.\n";
                break;
            }
            case 6:
            {
                queue.removeNegatives();
                cout << "Отрицательные числа удалены.\n";
                break;
            }
            case 7:
            {
                int value;
                cout << "Введите число для подсчета: ";
                cin >> value;
                int occurrences = queue.countOccurrences(value);
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