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

Node *InsertNthNode(Node *head, int element, int nth)
{
    Node *newNode = new Node();
    newNode->data = element;
    newNode->next = NULL;
    if (nth == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *newNode2 = head;
        for (int i = 1; i < nth - 1; i++)
        {
            newNode2 = newNode2->next;
        }
        newNode->next = newNode2->next;
        newNode2->next = newNode;
        return head;
    }
}

Node *DeleteNthNode(Node *head, int position)
{
    Node *newNode = head;
    if (position == 1)
    {
        head = newNode->next;
        delete head;
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            newNode = newNode->next;
        }
        Node *newNode2 = newNode->next;
        newNode->next = newNode2->next;
        delete newNode2;
        return head;
    }
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
    int n, i, x, y, nth;
    char m;
    cout << "Please enter the size of the list" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the numbers: " << endl;
        cin >> x;
        head = Insert(head, x);
        Print(head);
    }

    cout << "Do you want to insert a node in nth position? y/n?" << endl;
    cin >> m;

    if (m == 'y')
    {
        cout << "Please enter the #:" << endl;
        cin >> y;
        cout << "Please insert the position where you want to insert new node" << endl;
        cin >> nth;
        head = InsertNthNode(head, y, nth);
        Print(head);
    }
    if (m == 'y')
    {
        cout << "Please enter the position of the # to be deleted" << endl;
        cin >> nth;
        head = DeleteNthNode(head, nth);
        Print(head);
    }

    Print(head);
}