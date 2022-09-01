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
        if (next != NULL)
        {
            delete next;
        }
    }
};

bool detectLoop(Node *head)
{
    if (head == NULL)
        return;

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp])
            return true;
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
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
}