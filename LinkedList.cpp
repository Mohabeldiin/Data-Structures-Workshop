#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;
    Node *temp;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(int data)
    {
        temp = new Node;
        temp->data = data;
        if (isEmpty())
        {
            temp->next = nullptr;
            head = temp;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
    }

    void insertAtEnd(int data)
    {
        temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove(int data)
    {
        temp = head;
        Node *prev;
        while (temp->next != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == data)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if (temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void find(int data)
    {
        int i;
        for (i = 1, temp = head; temp->next != NULL && temp->data != data; temp = temp->next, i++)
            ;
        if (temp->data == data)
        {
            cout << "Found at position:" << i << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            for (temp = head; temp != NULL; temp = temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};

int main()
{
    LinkedList List;
    string choice;
    int element;
    while (true)
    {
        cout << "*--------------------------------------------------------------------*" << endl;
        cout << "1.INSERT  2.INSERT AT END  3.DISPLAY  4.FIND  5.ISEMPTY  6.REMOVE  7.EXIT " << endl;
        cout << "*--------------------------------------------------------------------*" << endl;
        cin >> choice;
        if (choice == "1")
        {
            cout << "Enter Element ";
            cin >> element;
            List.insert(element);
        }
        else if (choice == "2")
        {
            cout << "Enter Element ";
            cin >> element;
            List.insertAtEnd(element);
        }
        else if (choice == "3")
        {
            List.display();
        }
        else if (choice == "4")
        {
            cout << "Enter Element ";
            cin >> element;
            List.find(element);
        }
        else if (choice == "5")
        {
            if (List.isEmpty())
                cout << "List is Empty" << endl;
            else
                cout << "List is not Empty" << endl;
        }
        else if (choice == "6")
        {
            cout << "Enter Element ";
            cin >> element;
            List.remove(element);
        }
        else if (choice == "7")
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
