#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    
    
};

node* reverse(node* head)
{
    
    node* previous = head;
    if(previous == NULL)
        return head;
    node* current = head->next;
    node* temp = NULL;
    head->next=NULL;
    
    while(current != NULL)
    {
        
        temp = current->next;
        //temp->next = current->next;
        current->next = previous;
        previous = current;
        current = temp;
        //printList(current);
    }
    head = previous;
    
    return head;
}

node* push(node*, int);
void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int sum(node* head)
{
    int sum = 0;
    
    while(head!=NULL)
    {
        sum = (sum*10)+head->data;
        head = head->next;
    }
    return sum;
}

node* addlist(node* head1, node* head2)
{
    node* head = NULL;
    int add = 0;
    
    add = add + sum(head1);
    add = add + sum(head2);
    
    while(add!=0)
    {
        head = push(head,add%10);
        add = add/10;
    }
    
    return head;
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
 


int main()
{
    node* start = NULL;
    node* start2 = NULL;
    node* head = NULL;
        /* The constructed linked list is:
        1->2->3->4->5->6->7 */
        start = push(start,6);
        start = push(start,4);
        start = push(start,9);
        start = push(start,5);
        start = push(start,7);
        start2 = push(start2,4);
        start2 = push(start2,8);
    
    head = addlist(start,start2);
        printList(head);
        cout<<endl;
    
    return 0;
}

