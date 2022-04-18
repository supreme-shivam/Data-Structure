#include<iostream>
using namespace std;

struct node
{
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
    if(*head == NULL)
    {
        node* ptr = new node(x);
        ptr->next = ptr;
        *head = ptr;
        return;
    }
    node* temp = *head;
    
    do
    {
        if(temp->next == *head)
        {
            node* ptr = new node(x);
            temp->next = ptr;
            ptr->next = *head;
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
    while(temp != head);
}

void split(node*head, node** split, node** split2)
{
    node* slow = head;
    node* fast = head;
    
    while(fast->next!=head && fast->next->next!=head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *split2 = slow->next;
    slow->next = head;
    *split = head;
    
    if(fast->next == head)
        fast->next = *split2;
    else
        fast->next->next = *split2;
    
}

int main()
{
    node* start = NULL;
    
    node* v1 = NULL;
    node* v2 = NULL;
    
    push(&start,1);
    push(&start,2);
    push(&start,3);
    push(&start,4);
    push(&start,5);
    
    split(start,&v1,&v2);
    
    printlist(v1);
    cout<<endl;
    printlist(v2);
    
    return 0;
}
