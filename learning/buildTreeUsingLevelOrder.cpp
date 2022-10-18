#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void buildTreeUsingLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter root Node Data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << "Enter left Node Data for " << curr->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            curr->left = new Node(leftData);
            q.push(curr->left);
        }

        cout << "Enter right Node Data for " << curr->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            curr->right = new Node(rightData);
            q.push(curr->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (currNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << currNode->data << " ";
            if (currNode->left)
            {
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                q.push(currNode->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    buildTreeUsingLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}