#include <iostream>
#define maxsize 10
using namespace std;

class Queue
{
    int queue[maxsize];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool IsEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool IsFull()
    {
        return (rear + 1) % maxsize == front ? true : false;
    }

    void Enqueue(int data)
    {
        cout << "Enqueuing " << data << " \n";
        if (IsFull())
        {
            cout << "Error: Queue is Full\n";
            return;
        }
        else if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxsize;
        }
        queue[rear] = data;
    }

    void Dequeue()
    {
        cout << "Dequeuing \n";
        if (IsEmpty())
        {
            cout << "Error: Queue is Empty\n";
            return;
        }
        else if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % maxsize;
        }
    }

    int size()
    {
        return (rear - front + maxsize) % maxsize;
    }

    int Front()
    {
        if (front == -1)
        {
            cout << "Error: cannot return front from empty queue\n";
            return -1;
        }
        return queue[front];
    }

    void Print()
    {
        int count = (rear + maxsize - front) % maxsize + 1;
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % maxsize;
            cout << queue[index] << " ";
        }
        cout << "\n\n";
    }
};
int main()
{
    Queue queue;
    string choice;
    int element;
    while (true)
    {
        cout << "*--------------------------------------------------------------------*" << endl;
        cout << "1.ENQUEUE  2.DEQUEUE  3.DISPLAY  4.ISFULL  5.ISEMPTY  6.FRONT  7.SIZE  8.EXIT " << endl;
        cout << "*--------------------------------------------------------------------*" << endl;
        cin >> choice;
        if (choice == "1")
        {
            cout << "Enter Element ";
            cin >> element;
            queue.Enqueue(element);
        }
        else if (choice == "2")
        {
            queue.Dequeue();
        }
        else if (choice == "3")
        {
            queue.Print();
        }
        else if (choice == "4")
        {
            if (queue.IsFull())
                cout << "QUEUE IS FULL" << endl;
            else
                cout << "QUEUE IS NOT FULL" << endl
                     << "YOU CAN ENQUEUE" << endl;
        }
        else if (choice == "5")
        {
            if (queue.IsEmpty())
                cout << "QUEUE IS EMPTY" << endl;
            else
                cout << "QUEUE IS NOT EMPTY" << endl
                     << "YOU CAN DEQUEUE" << endl;
        }
        else if (choice == "6")
        {
            cout << "FRONT ELEMENT IS " << queue.Front() << endl;
        }
        else if (choice == "7")
        {
            cout << "SIZE OF QUEUE IS " << queue.size() << endl;
        }
        else if (choice == "8")
        {
            cout << "EXIT" << endl;
            break;
        }
        else
        {
            cout << "INVALID CHOICE" << endl;
        }
    }
}