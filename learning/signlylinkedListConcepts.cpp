#include <iostream>
#include <map>
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

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = tail->next;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *currentNode = head;
    int count = 1;

    while (count < position - 1)
    {
        currentNode = currentNode->next;
        count++;
    }

    if (currentNode->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void deleteNode(Node *&tail, Node *&head, int position)
{
    if (position == 1)
    {
        Node *currentNode = head;
        head = head->next;
        currentNode->next = NULL;
        delete currentNode;
    }
    else
    {
        Node *currentNode = head;
        Node *prevNode = NULL;

        int count = 1;

        while (count < position)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        prevNode->next = currentNode->next;
        if (currentNode->next == NULL)
        {
            tail = prevNode;
        }
        currentNode->next = NULL;
        delete currentNode;
    }
}

void print(Node *&head)
{
    Node *newNode = head;

    while (newNode != NULL)
    {
        cout << newNode->data << endl;
        newNode = newNode->next;
    }
    cout << endl;
}

Node *floydsAlgo(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return slow;
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydsAlgo(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head==NULL) return;

    Node*startLoop = getStartingNode(head);

    Node*temp = startLoop;

    while(temp->next != startLoop){
        temp = temp->next;
    }

    temp->next = NULL;

}

int main()
{
    Node *nodel = new Node(5);
    Node *head = nodel;
    Node *tail = nodel;
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 3, 13);
    InsertAtPosition(tail, head, 1, 4);
    InsertAtPosition(tail, head, 6, 17);
    InsertAtPosition(tail, head, 4, 19);
    // deleteNode(tail, head, 6);
    // print(head);

    tail->next = head->next;

    Node *loopstart = getStartingNode(head);

    cout << "loopstart: " << loopstart->data << endl;

    removeLoop(head);

    return 0;
}