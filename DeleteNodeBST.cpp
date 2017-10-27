#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *root, int data)
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

Node *FinMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            ;
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete (temp);
            return root;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete (temp);
            return root;
        }
        else
        {
            Node *temp = FinMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    /*Code To Test the logic
  Creating an example tree
            5
           / \
          3   10
         / \   \
        1   4   11
*/
    Node *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    // Deleting node with value 5, change this value to test other cases
    root = Delete(root, 3);

    //Print Nodes in Inorder
    cout << "Inorder: ";
    InOrder(root);
    cout << "\n";
    return 0;
}