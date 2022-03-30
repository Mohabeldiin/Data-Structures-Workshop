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
    List.display();
    List.insert(15);
    List.display();
    List.insert(25);
    List.display();
    List.insert(35);
    List.display();
    List.insert(45);
    List.display();
    List.find(15);
    List.remove(25);
    List.display();
    List.insertAtEnd(55);
    List.insertAtEnd(65);
    List.display();
}
