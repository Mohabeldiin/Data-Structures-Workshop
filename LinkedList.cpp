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
    bool isEmpty()
    {
        return head == nullptr;
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    int GetInput()
    {
        string element;
        cout << "Enter Element ";
        cin >> element;
        for (int i = 0; i < element.length(); i++)
            if (!isdigit(element[i]))
            {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                return GetInput();
            }
        return stoi(element);
    }

    void isEmptyCheck()
    {
        if (isEmpty())
            cout << "List is empty." << endl;
        else
            cout << "List is not empty." << endl;
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
    while (true)
    {
        system("cls");
        cout << "*------------------------------------------------------------------------------------*" << endl;
        cout << "1.INSERT 2.ASSIGNMENT  3.INSERT AT END  4.DISPLAY 5.FIND  6.ISEMPTY  7.REMOVE  8.EXIT " << endl;
        cout << "*------------------------------------------------------------------------------------*" << endl;
        cin >> choice;

        if (choice == "1")
            List.insert(List.GetInput());
        else if (choice == "2")
            continue; // assignment code here
        else if (choice == "3")
            List.insertAtEnd(List.GetInput());
        else if (choice == "4")
            List.display();
        else if (choice == "5")
            List.find(List.GetInput());
        else if (choice == "6")
            List.isEmptyCheck();
        else if (choice == "7")
            List.remove(List.GetInput());
        else if (choice == "8")
            break;
        else
            cout << "INVALID CHOICE" << endl;

        system("pause");
    }
    cout << "EXIT" << endl;
    return 0;
}