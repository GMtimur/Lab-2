#pragma once
#include <stdexcept>

using namespace std;

template <typename T>

/// <summary>
/// Класс `Queue` реализует структуру данных "очередь" с использованием связного списка.
/// Очередь работает по принципу "Первый пришел, первый вышел" (FIFO — First In, First Out).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в очереди.</typeparam>
/// <remarks>
/// Основные операции:
/// - `queue(T value)`: Добавляет элемент в конец очереди.
/// - `unqueue()`: Удаляет и возвращает элемент из начала очереди.
/// - `count()`: Возвращает количество элементов в очереди.
/// - `clear()`: Очищает очередь.
/// </remarks>
class Queue 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head;
    Node* tail;
    int counter;

public:
    Queue() : head(nullptr), tail(nullptr), counter(0) {}

    ~Queue() 
    {
        clear();
    }

    void queue(T data) 
    {
        Node* newNode = new Node(data);
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

    T unqueue() 
    {
        if (head == nullptr) 
        {
            throw out_of_range("Очередь пуста.");
        }
        Node* temp = head;
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

    int count() const 
    {
        return counter;
    }

    void clear() 
    {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        counter = 0;
    }

    void insertBeforeNegatives() 
    {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) 
        {
            if (current->data < 0) 
            {
                Node* newNode = new Node(1);
                if (prev == nullptr) 
                {
                    newNode->next = head;
                    head = newNode;
                }
                else 
                {
                    newNode->next = current;
                    prev->next = newNode;
                }
                counter++;
                prev = newNode;
            }
            else 
            {
                prev = current;
            }
            current = current->next;
        }
    }

    void removeNegatives() 
    {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) 
        {
            if (current->data < 0) 
            {
                Node* temp = current;
                if (prev == nullptr) 
                {
                    head = current->next;
                } 
                else 
                {
                    prev->next = current->next;
                }
                if (current == tail) 
                {
                    tail = prev;
                }
                current = current->next;
                delete temp;
                counter--;
            } 
            else 
            {
                prev = current;
                current = current->next;
            }
        }
    }

    int countOccurrences(T value) const
    {
        int count = 0;
        Node* current = head;
        while (current != nullptr) 
        {
            if (current->data == value) 
            {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};