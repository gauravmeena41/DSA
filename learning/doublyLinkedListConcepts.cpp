#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next == NULL;
        }
    }
};

void getLength(Node *head)
{
    Node *currentNode = head;
    int length = 0;

    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        length++;
    }
    cout << "length " << length << endl;
}

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    Node *currentNode = head;
    int count = 1;

    while (count < position - 1)
    {
        currentNode = currentNode->next;
        count++;
    }

    Node *newNode = new Node(data);
    if (currentNode->next == NULL)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    newNode->next = currentNode->next;
    currentNode->next->prev = newNode;
    currentNode->next = newNode;
    newNode->prev = currentNode;
}

void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *currentNode = head;
        currentNode->next->prev = NULL;
        head = currentNode->next;
        currentNode->next = NULL;
        delete currentNode;
        return;
    }
    else
    {
        Node *currentNode = head;
        int count = 1;

        while (count < position)
        {
            currentNode = currentNode->next;
            count++;
        }

        currentNode->prev->next = currentNode->next;
        currentNode->prev = NULL;
        currentNode->next = NULL;
        delete currentNode;
    }
}

void print(Node *head)
{
    Node *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
    cout << endl;
}

int main()
{
    // Node *nodel = new Node(5);
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 5);
    InsertAtTail(head, tail, 20);
    InsertAtPosition(tail, head, 2, 6);
    InsertAtPosition(tail, head, 3, 7);
    InsertAtPosition(tail, head, 1, 1);
    InsertAtPosition(tail, head, 5, 10);

    deleteNode(head, 6);
    print(head);
}