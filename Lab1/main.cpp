#include <iostream>
#include "stack.h"

using namespace std;

int main() 
{
    Stack<int> stack;
    int value;
    
    while(cin >> value && value != 0) 
    {
        stack.push(value);
    }
    
    while(stack.count() > 0) 
    {
        int num = stack.pop();
        if(num > 0) 
        {
            cout << num << " ";
        }
    }

    return 0;
}