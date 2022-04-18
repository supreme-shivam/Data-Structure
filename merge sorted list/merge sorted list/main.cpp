#include <iostream>
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

node* push_back(node* head, int x)
{
    node* new_node = new node(x);
    if(head==NULL)
        return new_node;
    node* next = head;
    
    while(next->next!=NULL)
    {
        next = next->next;
    }
    next->next = new_node;
    
    return head;
}

node* merge(node* a,node* b)
{
    if(a==NULL && b==NULL)
        return a;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    
    
    node* head = NULL;
    while(a!=NULL && b!=NULL)
    {
//        if(a->data == b->data)
//        {
//            head = push_back(head, a->data);
//            a = a->next;
//        }
        if(a->data <= b->data)
        {
            head = push_back(head, a->data);
            a = a->next;
        }
        else
        {
            head = push_back(head, b->data);
            b = b->next;
        }
//        if(a==NULL && b==NULL)
//            break;
        if(a==NULL)
        {
            node* work = head;
            while(work->next!=NULL)
            {
                work = work->next;
            }
            work->next = b;
        }
        if(b==NULL)
        {
            node* work = head;
            while(work->next!=NULL)
            {
                work = work->next;
            }
            work->next = a;
        }
    }
    return head;
}

void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    node* a1 = NULL;
    node* a2 = NULL;
    
    a1 = push_back(a1,5);
    a1 = push_back(a1,10);
    a1 = push_back(a1,20);
    
    a2 = push_back(a2,6);
    a2 = push_back(a2,12);
    a2 = push_back(a2,13);
    
    //printList(a2);
    
    a1 = merge(a1,a2);
    
    
    
    printList(a1);
    
    
    
    
    return 0;
}
