#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void printList(node*);

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
 


int main()
{
    node* start = NULL;
        /* The constructed linked list is:
        1->2->3->4->5->6->7 */
        start = push(start,7);
        start = push(start,6);
        start = push(start,5);
        start = push(start,4);
        start = push(start,3);
        start = push(start,2);
        start = push(start,1);
    
        printList(start);
        cout<<endl;
     
        start = reverse(start);
     
        //cout << "\nLinked list after calling swapNodes() ";
        printList(start);
        cout<<endl;
    
    return 0;
}
