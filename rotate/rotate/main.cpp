#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

node* push(node* head_ref, int new_data)
{
    node* new_node = new node();
 
    new_node->data = new_data;
 
    new_node->next = head_ref;
 
    head_ref = new_node;
    //printList(head_ref);
    return head_ref;
}

node* rotate(node* head,int x)
{
    if(head==NULL || head->next==NULL)
        return head;
    node* current = head;
    node* previous;
    node* head2;
    
    for(int i=1;i<x;i++)
    {
        current = current->next;
    }
    previous = current;
    head2 = current->next;
    
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = head;
    previous->next = NULL;
    head = head2;
    
    return head;
}

int main()
{
    node* start = NULL;
        /* The constructed linked list is:
        1->2->3->4->5->6->7 */
        start = push(start,60);
        start = push(start,50);
        start = push(start,40);
        start = push(start,30);
        start = push(start,20);
        start = push(start,10);
        //start = push(start,8);
    
    start = rotate(start,4);
        printList(start);
        cout<<endl;
    
    return 0;
}
 
