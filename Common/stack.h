#pragma once
#include <stdexcept>
#include "node.h"

using namespace std;

/// <summary>
/// Класс `Stack` реализует структуру данных "стек" с использованием связного списка.
/// Стек работает по принципу "Последний пришел, первый вышел" (LIFO — Last In, First Out).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в стеке.</typeparam>
template <typename T>
class Stack 
{
private:
    Node<T>* top;
    int counter;

public:
    Stack() : top(nullptr), counter(0) {}
    ~Stack() 
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент на вершину стека.
    /// </summary>
    /// <param name="value">Значение, которое нужно добавить в стек.</param>
    void push(T value) 
    {
        top = new Node<T>(value, top); 
        counter++;
    }

    /// <summary>
    /// Удаляет и возвращает элемент с вершины стека.
    /// </summary>
    /// <returns>Значение элемента на вершине стека.</returns>
    /// <exception cref="out_of_range">Выбрасывается, если стек пуст.</exception>
    T pop() 
    {
        if (top == nullptr) 
        {
            throw out_of_range("Stack is empty");
        }
        Node<T>* temp = top;
        T value = temp->data;
        top = top->next;
        delete temp;
        counter--;
        return value;
    }

    /// <summary>
    /// Возвращает значение элемента на вершине стека без его удаления.
    /// </summary>
    /// <returns>Значение элемента на вершине стека.</returns>
    /// <exception cref="out_of_range">Выбрасывается, если стек пуст.</exception>
    T peek() const 
    {
        if (top == nullptr) 
        {
            throw out_of_range("Stack is empty");
        }
        return top -> data;
    }

    /// <summary>
    /// Возвращает количество элементов в стеке.
    /// </summary>
    /// <returns>Количество элементов в стеке.</returns>
    int count() const 
    {
        return counter;
    }

    /// <summary>
    /// Очищает стек, удаляя все элементы.
    /// </summary >
    void clear() 
    {
        while (top != nullptr) 
        {
            Node<T>* temp = top;
            top = top -> next;
            delete temp;
        }
        counter = 0;
    }
};