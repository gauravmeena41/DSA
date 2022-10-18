#include <iostream>
#include <queue>
#include <algorithm>
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

void reverseLevelOrderTraversal(vector<vector<int>> &ans, Node *root, int level)
{
    if (!root)
        return;

    if (level >= ans.size())
        ans.push_back({});

    ans[level].push_back(root->data);
    reverseLevelOrderTraversal(ans, root->left, level + 1);
    reverseLevelOrderTraversal(ans, root->right, level + 1);
}

int main()
{

    Node *root = NULL;
    vector<vector<int>> ans;

    root = buildTree(root);

    reverseLevelOrderTraversal(ans, root, 0);

    reverse(ans.begin(), ans.end());

    for (vector<int> v : ans)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
