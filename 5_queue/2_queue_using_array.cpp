// ! Write a program to implement queue using array

#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int *Q;
    int front;
    int rear;

public:
    // * Constructors
    Queue() // ? default construtor
    {
        size = 5;
        front = rear = -1;
        Q = new int[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    // * -------------

    //  * Member Functions

    void enqueue(int);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << endl
             << "Queue is Full !";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;

    if (front == rear)
    {
        cout << endl
             << "Queue is Empty !";
    }
    else
    {
        x = Q[front + 1];
        front++;
    }

    return x;
}

void Queue::display()
{
    cout << endl
         << "Queue is : ";

    for (int i = front + 1; i <= rear; i++)
    {
        cout << "\t" << Q[i];
    }
}

// *--------------- MAIN --------------
int main()
{
    Queue q[5];

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);

    q->display();

    q->dequeue();
    q->display();

    q->dequeue();
    q->display();
    return 0;
}