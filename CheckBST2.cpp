#include <climits>
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

bool IsBSTUtil(Node *root, int minValue, int maxValue){
    if(root==NULL) return true;
    if(root->data>minValue&&root->data<maxValue
        &&IsBSTUtil(root->left,minValue,root->data)&&
        IsBSTUtil(root->right,root->data,maxValue)){
            return true;
        }
    else{
        return false;
    }
}

bool IsBST(Node *root){
    return IsBSTUtil(root,INT_MIN,INT_MAX);
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
    if (IsBST(root) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}