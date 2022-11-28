#include <iostream>
#include <vector>
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

int getBinaryTreeHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int leftLevel = getBinaryTreeHeight(root->left);
    int rightLevel = getBinaryTreeHeight(root->right);

    return max(leftLevel, rightLevel) + 1;
}

int getBinaryTreeDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int leftDia = getBinaryTreeDiameter(root->left);
    int rightDia = getBinaryTreeDiameter(root->right);
    int rootHeight = getBinaryTreeHeight(root->left) + getBinaryTreeHeight(root->right) + 1;

    return max(leftDia, max(rightDia, rootHeight));
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << getBinaryTreeDiameter(root) << endl;

    return 0;
}