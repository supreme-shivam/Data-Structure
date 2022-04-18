#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* previous;
    
    node()
    {
        data = NULL;
        next = NULL;
        previous = NULL;
    }
    node(int x)
    {
        data = x;
        next = NULL;
        previous = NULL;
    }
};

void print(node* a)
{
    while(a!=NULL)
    {
        cout<<a->data<<" ";
        a = a->next;
    }
    cout<<endl;
}
void printy(node* a)
{
    while(a!=NULL)
    {
        cout<<a->data<<" ";
        a = a->previous;
    }
    cout<<endl;
}

int main()
{
    
    int i;
    
    for(i=0;i<6;i++)
    {
        node* head = new node(1);
        
    }
    
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    
    head->next = second;
    
    second->previous = head;
    second->next = third;
    
    third->next = fourth;
    third->previous = second;
    
    fourth->previous = third;
    
    printy(fourth);
    
    return 0;
}
