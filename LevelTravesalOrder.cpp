#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *getNewNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node *Insert(Node *root, char data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
}

int main()
{
    Node *root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    root = Insert(root, 'Z');
    LevelOrder(root);

    return 0;
}