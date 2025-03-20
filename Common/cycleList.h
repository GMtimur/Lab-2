#include <iostream>
#include <stdexcept>
#include "node.h"

using namespace std;

/// <summary>
/// Класс `CycleList` реализует структуру данных "односвязный циклический список".
/// Список поддерживает произвольный доступ к элементам и основные операции: добавление, вставку, удаление и очистку.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
template <typename T>
class CycleList 
{
private:
    Node<T>* head;
    Node<T>* tail;
    int counter;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    CycleList() : head(nullptr), tail(nullptr), counter(0) {}

    /// <summary>
    /// Деструктор. Очищает список при уничтожении объекта.
    /// </summary>
    ~CycleList() 
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент в конец списка.
    /// </summary>
    /// <param name="data">Данные для добавления.</param>
    void add(T data) 
    {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) 
        {
            head = tail = newNode;
            tail->next = head;
        } 
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        counter++;
    }

    /// <summary>
    /// Вставляет элемент в указанную позицию.
    /// </summary>
    /// <param name="index">Позиция для вставки (индексация с 0).</param>
    /// <param name="data">Данные для вставки.</param>
    /// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
    void insert(int index, T data) 
    {
        if (index < 0 || index > counter)
        {
            throw out_of_range("Index out of range");
        }
        if (index == counter) 
        {
            add(data);
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        if (index == 0) 
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        counter++;
    }

    /// <summary>
    /// Удаляет элемент из списка по указанному индексу.
    /// </summary>
    /// <param name="index">Позиция для удаления (индексация с 0).</param>
    /// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
    void removeAt(int index)
    {
        if (index < 0 || index >= counter)
        {
            throw out_of_range("Index out of range");
        }
        Node<T>* toDelete;
        if (index == 0)
        {
            toDelete = head;
            head = head->next;
            tail->next = head;
            if (counter == 1)
            {
                head = tail = nullptr;
            }
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            if (index == counter - 1)
            {
                tail = current;
            }
        }
        delete toDelete;
        counter--;
    }

    /// <summary>
    /// Возвращает ссылку на элемент по указанному индексу.
    /// </summary>
    /// <param name="index">Индекс элемента (индексация с 0).</param>
    /// <returns>Ссылка на данные элемента.</returns>
    /// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
    T& operator[](const int index)
    {
        if (index < 0 || index >= counter)
        {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    /// <summary>
    /// Возвращает количество элементов в списке.
    /// </summary>
    /// <returns>Количество элементов.</returns>
    int count() const
    {
        return counter;
    }

    /// <summary>
    /// Подсчитывает количество вхождений указанного значения в списке.
    /// </summary>
    /// <param name="data">Значение для подсчета.</param>
    /// <returns>Количество вхождений.</returns>
    int countOccurrences(T data) const
    {
        int cnt = 0;
        Node<T>* current = head;
        for (int i = 0; i < counter; i++)
        {
            if (current->data == data)
            {
                cnt++;
            }
            current = current->next;
        }
        return cnt;
    }

    /// <summary>
    /// Очищает список, удаляя все элементы.
    /// </summary>
    void clear()
    {
        while (counter > 0)
        {
            removeAt(0);
        }
    }
};