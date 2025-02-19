#pragma once
#include <stdexcept>

using namespace std;

template <typename T>

/// <summary>
/// Класс `Stack` реализует структуру данных "стек" с использованием связного списка.
/// Стек работает по принципу "Последний пришел, первый вышел" (LIFO — Last In, First Out).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в стеке.</typeparam>
/// <remarks>
/// Основные операции:
/// - `push(T value)`: Добавляет элемент на вершину стека.
/// - `pop()`: Удаляет и возвращает элемент с вершины стека.
/// - `peek()`: Возвращает элемент с вершины стека без его удаления.
/// - `count()`: Возвращает количество элементов в стеке.
/// - `clear()`: Очищает стек.
/// </remarks>
class Stack 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}
    ~Stack() 
    {
        clear();
    }

    void push(T value) 
	{
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop() 
	{
        if (top == nullptr) 
		{
            throw out_of_range("Stack is empty");
        }
        T value = top->data;
	top = top->next;
        size--;
        return value;
    }

    T peek() const 
	{
        if (top == nullptr) 
		{
            throw out_of_range("Stack is empty");
        }
        return top -> data;
    }

    int count() const 
	{
        return size;
    }

    void clear() 
	{
        while (top != nullptr) 
		{
            Node* temp = top;
            top = top -> next;
            delete temp;
        }
        size = 0;
    }
};