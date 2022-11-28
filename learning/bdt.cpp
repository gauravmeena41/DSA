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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertToBst(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (root->data < data)
    {
        root->right = insertToBst(root->right, data);
    }
    else
    {
        root->left = insertToBst(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertToBst(root, data);
        cin >> data;
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
    cout << "Enter data to create binary search tree" << endl;
    takeInput(root);

    levelOrderTraversal(root);
    return 0;
}