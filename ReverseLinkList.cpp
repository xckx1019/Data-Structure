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

Node *Reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    return head;
}

int main()
{
    Node *head = NULL;      //Local variable
    head = Insert(head, 2); //Insert: Node* Insert(Node* head, int data)
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head);
    Print(head);

    return 0;
}