#include <iostream>
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
    newNode->left = NULL;
    newNode->right = NULL;
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

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    InOrder(root->left);
    InOrder(root->right);
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    PreOrder(root->left);
    cout << root->data << " ";
    PreOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PreOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    //Print Nodes in Preorder.
    cout << "Preorder: ";
    PreOrder(root);
    cout << "\n";
    //Print Nodes in Inorder
    cout << "Inorder: ";
    InOrder(root);
    cout << "\n";
    //Print Nodes in Postorder
    cout << "Postorder: ";
    PostOrder(root);
    cout << "\n";
    return 0;
}