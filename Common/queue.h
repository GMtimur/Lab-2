#pragma once
#include <stdexcept>
#include "node.h"

using namespace std;

/// <summary>
/// Класс `Queue` реализует структуру данных "очередь" с использованием связного списка.
/// Очередь работает по принципу "Первый пришел, первый вышел" (FIFO — First In, First Out).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в очереди.</typeparam>
template <typename T>
class Queue 
{
private:
    Node<T>* head;
    Node<T>* tail;
    int counter;

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустую очередь.
    /// </summary>
    Queue() : head(nullptr), tail(nullptr), counter(0) {}

    /// <summary>
    /// Деструктор. Очищает очередь, освобождая всю выделенную память.
    /// </summary>
    ~Queue() 
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент в конец очереди.
    /// </summary>
    /// <param name="data">Элемент, который нужно добавить в очередь.</param>
    void queue(T data) 
    {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }

    /// <summary>
    /// Удаляет и возвращает элемент из начала очереди.
    /// </summary>
    /// <returns>Элемент, удаленный из начала очереди.</returns>
    /// <exception cref="std::out_of_range">Выбрасывается, если очередь пуста.</exception>
    T unqueue() 
    {
        if (head == nullptr) 
        {
            throw out_of_range("Очередь пуста.");
        }
        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        if (head == nullptr) 
        {
            tail = nullptr;
        }
        delete temp;
        counter--;
        return data;
    }

    /// <summary>
    /// Возвращает количество элементов в очереди.
    /// </summary>
    /// <returns>Количество элементов в очереди.</returns>
    int count() const 
    {
        return counter;
    }

    /// <summary>
    /// Очищает очередь, удаляя все элементы.
    /// </summary>
    void clear() 
    {
        while (head != nullptr) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        counter = 0;
    }
};