#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        ;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void InsertNode(Node *&tail, int element, int data)
{
    Node *newNode = new Node(data);

    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *currentNode = tail;
        while (currentNode->data != element)
        {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
        return;
    else
    {
        Node *prevNode = tail;
        Node *currentNode = prevNode->next;

        while (currentNode->data != element)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        prevNode->next = currentNode->next;

        if (currentNode == prevNode)
            tail = NULL;
        else if (currentNode == tail)
            tail = prevNode;

        currentNode->next = NULL;
        delete currentNode;
    }
}

void print(Node *&tail)
{
    Node *currentNode = tail;

    if (tail == NULL)
        return;

    do
    {
        cout << tail->next->data << endl;
        tail = tail->next;
    } while (currentNode != tail);
}

int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 7);
    InsertNode(tail, 7, 6);

    deleteNode(tail, 6);

    print(tail);

    cout << "head ->" << tail->next->data << endl;
    cout << "tail ->" << tail->data << endl;

    return 0;
}