#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Insert(Node *head, int num)
{
    Node *newNode = new Node();
    newNode->data = num;
    newNode->next = NULL;

    if (head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
    return head;
}

void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);
    Print(head);
}