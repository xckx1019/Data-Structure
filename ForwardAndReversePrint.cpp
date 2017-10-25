#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Insert(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->data = data;
    if (head != NULL)
    {
        newNode->next = head;
    }
    head = newNode;
    return head;
}

void ForwardPrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    ForwardPrint(head->next);
}

void ReversePrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    ReversePrint(head->next);
    cout << head->data << " ";
}

int main()
{
    Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    ReversePrint(head);
    cout << endl;
    ForwardPrint(head);
}