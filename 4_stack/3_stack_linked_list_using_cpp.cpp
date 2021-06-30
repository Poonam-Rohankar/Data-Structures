#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top; // Top pointer

public:
    Stack() { top = NULL; }

    void push(int);
    int pop();
    void Display();
};

void Stack::push(int x)
{
    Node *new_node = new Node;

    if (new_node == NULL)
    {
        cout << "Stack is Full !";
    }
    else
    {
        new_node->data = x;
        new_node->next = top;
        top = new_node;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is Empty !";
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *ptr = top;

    cout << endl
         << "Stack is : ";

    while (ptr != NULL)
    {
        cout << "\t" << ptr->data;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    stk.Display();

    stk.pop();
    stk.Display();
    return 0;
}