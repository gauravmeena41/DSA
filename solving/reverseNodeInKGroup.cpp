#include <iostream>
#include <vector>
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
    }
};

void InsertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node *&head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
}

int main()
{
    Node *nodel = new Node(1);
    Node *head = nodel;
    Node *tail = nodel;

    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 5);

    Node *prevNode = head;
    Node *currentNode = head->next;

    vector<int> kGroups = {3, 3, 5};

    // print(prevNode);

    return 0;
}