#include<iostream>
using namespace std;

struct node
{
    int data;
    node* previous;
    node* next;
};

void push(node** head,int x)
{
    if(*head==NULL)
    {
        *head = new node();
        (*head)->data = x;
        (*head)->previous = NULL;
        (*head)->next = NULL;
        return;
    }
    
    node* temp = *head;
    
    while(temp!=NULL)
    {
        if(temp->next == NULL)
        {
            node* ptr = new node();
            temp->next = ptr;
            ptr->data = x;
            ptr->previous = temp;
            ptr->next = NULL;
            return;
        }
        temp = temp->next;
    }
}

void printlist(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
}

void delet(node** head,node* del)
{
    if(del == *head)
    {
        *head = del->next;
        free(del);
        return;
    }
    node* temp = *head;
    
    while(temp!=del)
    {
        if((temp->next == del) && (temp->next->next == NULL))
        {
            free(temp->next);
            temp->next = NULL;
            return;
        }
        
        if(temp->next == del)
        {
            temp->next->next->previous = temp;
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }
        temp = temp->next;
    }
    
}


int main()
{
    node* h1 = NULL;
    
    push(&h1,1);
    push(&h1,2);
    push(&h1,3);
    push(&h1,4);
    push(&h1,5);
    
    delet(&h1,h1);
    
    printlist(h1);
    
    return 0;
}
