#include <iostream>
#include <stdexcept>
#include "node.h"

using namespace std;

/// <summary>
/// Класс `CycleList` реализует структуру данных "односвязный циклический список"
/// с минимальным хранением состояния (только tail pointer).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
template <typename T>
class CycleList 
{
private:
    Node<T>* tail;
    int counter;

    /// <summary>
    /// Возвращает указатель на голову списка (первый элемент).
    /// Для пустого списка возвращает nullptr.
    /// </summary>
    /// <returns>Указатель на головной узел списка.</returns>
    Node<T>* head() const
    {
        if (tail == nullptr)
        {
            return nullptr;
        }
        return tail->next;
    }

    Node<T>* getNodeAt(int index) const 
{
    if (index < 0 || index >= counter) 
    {
        throw out_of_range("Index out of range");
    }

    if (index <= counter / 2) 
    {
        // Идём от head вперед
        Node<T>* current = head();
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
        return current;
    } 
    else 
    {
        Node<T>* current = tail;
        for (int i = counter; i > index; i--) 
        {
            current = current->next;
        }
        return current;
    }
}

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    CycleList() : tail(nullptr), counter(0) {}

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
        if (tail == nullptr) 
        {
            tail = newNode;
            tail->next = tail;
        } 
        else 
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
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
        if (index < 0) 
        {
            throw out_of_range("Index out of range");
        }

        Node<T>* newNode = new Node<T>(data);
        if (index == counter) 
        {
            add(data);  // Вставка в конец
            return;
        }

        Node<T>* prev = (index == 0) ? tail : getNodeAt(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
        
        if (index == 0) 
        {
            tail->next = newNode;  // Обновляем head (tail->next)
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
            toDelete = head();
            if (counter == 1) 
            {
                tail = nullptr;
            } 
            else 
            {
                tail->next = toDelete->next;
            }
        } 
        else 
        {
            Node<T>* prev = getNodeAt(index - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            
            if (index == counter - 1) 
            {
                tail = prev;
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
    T& operator[](int index) 
    {
        return getNodeAt(index)->data;
    }

    const T& operator[](int index) const 
    {
        return getNodeAt(index)->data;
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
        if (counter == 0) return 0;
        
        int cnt = 0;
        Node<T>* current = head();
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
        if (counter == 0) return;
        
        Node<T>* current = head();
        for (int i = 0; i < counter; i++)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        tail = nullptr;
        counter = 0;
    }
};