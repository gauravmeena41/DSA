#include <iostream>
#include <queue>
#include <stack>

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

void inOrderTraversal(Node *root)
{
    // if (root == NULL)
    //     return;

    // inOrderTraversal(root->left);

    // cout << root->data << " ";

    // inOrderTraversal(root->right);

    stack<Node *> s;
    Node *currNode = root;

    while (currNode != NULL || !s.empty())
    {
        while (currNode != NULL)
        {
            s.push(currNode);
            currNode = currNode->left;
        }

        currNode = s.top();
        s.pop();

        cout << currNode->data << " ";
        currNode = currNode->right;
    }
}

void preOrderTraversal(Node *root)
{
    // if (root == NULL)
    //     return;

    // cout << root->data << " ";
    // preOrderTraversal(root->left);
    // preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // if (root == NULL)
    //     return;
    // postOrderTraversal(root->left);
    // postOrderTraversal(root->right);
    // cout << root->data << " ";
}

int main()
{

    Node *root = NULL;

    root = buildTree(root);

    inOrderTraversal(root);

    return 0;
}