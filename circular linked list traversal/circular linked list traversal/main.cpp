#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
        node(int x)
        {
            data = x;
            next = NULL;
        }
    
};

void push(node** head,int x)
{
    if(*head==NULL)
    {
        node* ptr1 = new node(x);
        ptr1->next = ptr1;
        *head = ptr1;
        return;
    }
    
    node* temp = *head;
    
    do
    {
        if(temp->next == *head)
        {
            node* ptr1 = new node(x);
            temp->next = ptr1;
            ptr1->next = *head;
            return;
        }
        temp = temp->next;
    }
    while(temp != *head);
}



void printlist(node* head)
{
    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp!=head);
}


int main()
{
    node* start = NULL;
    
    push(&start,1);
    push(&start,2);
    push(&start,3);
    push(&start,4);
    push(&start,5);
    
    printlist(start);
    
    
    return 0;
}
