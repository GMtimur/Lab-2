#pragma once

using namespace std;

template <typename T>

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
        Node* temp = top;
        T value = temp->data;
        top = top->next;
        delete temp;
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