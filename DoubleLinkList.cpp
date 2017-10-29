#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *InsertAtHead(Node *head, int data){
    Node *newNode=new Node();
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if (head==NULL){
        head=newNode;
    }
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;

    }
    return head;
}

void Print(Node *head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node *head=NULL;
    head=InsertAtHead(head,6);
    Print(head);
    head=InsertAtHead(head,8);
    Print(head);

    return 0;
}