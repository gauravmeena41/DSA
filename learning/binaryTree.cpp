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

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for left: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right: " << data << endl;
    root->right = buildTree(root->right);

    return root;
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

    root = buildTree(root);

    levelOrderTraversal(root);

    return 0;
}