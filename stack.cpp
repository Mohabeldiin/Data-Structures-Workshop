#include <iostream>
#define maxsize 10
using namespace std;

class Stack
{
    int top;
    int stack[maxsize];

public:
    Stack()
    {
        top = 0;
    }

    bool isfull()
    {
        return top == maxsize;
    }

    bool isempty()
    {
        return top == 0;
    }

    void push(int data)
    {
        if (isfull())
        {
            cout << "Stack is Full" << endl;
            return;
        }
        else
            stack[top] = data;
        top++;
    }

    void pop()
    {
        if (isempty())
        {
            cout << "Nothing in List" << endl;
            return;
        }
        else
            top--;
        cout << "pops " << stack[top] << endl;
    }

    void display()
    {
        if (top == 0)
        {
            cout << "Nothing to display" << endl;
        }
        else
            cout << "Displaying" << endl;
        for (int i = 0; i < top; i++)
        {
            cout << stack[i] << endl;
        }
    }

    void Top()
    {
        cout << "Top is " << stack[top - 1] << endl;
    }

    void Size()
    {
        cout << "Size of Stack is " << top << endl;
    }
};
int main()
{
    Stack stack;
    string choice;
    int element;
    while (true)
    {
        cout << "*--------------------------------------------------------------------*" << endl;
        cout << "1.PUSH  2.POP  3.DISPLAY  4.ISFULL  5.ISEMPTY  6.TOP  7.SIZE  8.EXIT " << endl;
        cout << "*--------------------------------------------------------------------*" << endl;
        cin >> choice;
        if (choice == "1")
        {
            cout << "Enter Element ";
            cin >> element;
            stack.push(element);
        }
        else if (choice == "2")
        {
            stack.pop();
        }
        else if (choice == "3")
        {
            stack.display();
        }
        else if (choice == "4")
        {
            if (stack.isfull())
                cout << "STACK IS FULL" << endl;
            else
                cout << "STACK IS NOT FULL" << endl
                     << "YOU CAN PUSH" << endl;
        }
        else if (choice == "5")
        {
            if (stack.isempty())
                cout << "STACK IS EMPTY" << endl;
            else
                cout << "STACK IS NOT EMPTY" << endl
                     << "YOU CAN POP" << endl;
        }
        else if (choice == "6")
        {
            stack.Top();
        }
        else if (choice == "7")
        {
            stack.Size();
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
    return 0;
}
