#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};

node* pushfront(node* p)
{
    node* new_node = new node();
    
    new_node->data = 0;
    new_node->next = p;
    
    return new_node;
    
}

void push_front(node *p)
{
    node* new_node = new node();
    new_node->data = p->data;
    new_node->next = p->next;
    p->next = new_node;
    p->data = 111;
    
}

void push_back(node* p)
{
    node* new_node = new node();
    new_node->data = 4;
    new_node->next = NULL;
    p->next = new_node;
}

void push_between(node* p,node* q)
{
    node* new_node = new node();
    new_node->data = 1010;
    new_node->next = p->next;
    p->next = new_node;
}

void print(node* p)
{
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main()
{
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    push_front(head);
    push_between(second, third);
    push_back(third);
    
    print(head);
    
    
    
    
    return 0;
}
