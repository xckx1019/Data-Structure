#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

bool IsSubtreeLesser(Node *root, int data){
    if(root==NULL) return true;
    if(root->data<=data
        &&IsSubtreeLesser(root->left,data)
        &&IsSubtreeLesser(root->right,data)){
            return true;
        }
    else {
        return false;
    }
}

bool IsSubtreeGreater(Node *root, int data)
{
    if (root == NULL)
        return true;
    if (root->data >= data 
        && IsSubtreeGreater(root->left, data) 
        && IsSubtreeGreater(root->right, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node *root){
    if(root==NULL)
        return true;
    if(IsSubtreeLesser(root->left,root->data)
    &&IsSubtreeGreater(root->right,root->data)
    &&IsBinarySearchTree(root->left)
    &&IsBinarySearchTree(root->right)){
        return true;
    }
    else {
        return false;
    }
}

Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
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

int main()
{
    Node *root = NULL; // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    // Ask user to enter a number.

    //If number is found, print "FOUND"
    if (IsBinarySearchTree(root) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}