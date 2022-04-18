#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* swapnodes(node* head,int x,int y)
{
    if(x==y)
        return head;
    
    node* currentx = head;
    node* previousx = NULL;
    
    while(currentx->data != x)
    {
        previousx = currentx;
        currentx = currentx->next;
    }
    
    node* currenty = head;
    node* previousy = NULL;
    
    while(currenty->data != y)
    {
        previousy = currenty;
        currenty = currenty->next;
    }
    
    if(currentx == NULL || currenty == NULL)
        return head;
    
    if(previousx != NULL)
        previousx->next = currenty;
    else
        head = currenty;
    
    if(previousy != NULL)
        previousy->next = currentx;
    else
        head = currentx;
    
    node* temp = currenty->next;
    currenty->next = currentx->next;
    currentx->next = temp;
    
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
     
        cout << "Linked list before calling swapNodes() ";
        printList(start);
        cout<<endl;
     
        start = swapnodes(start, 4, 3);
     
        cout << "\nLinked list after calling swapNodes() ";
        printList(start);
        cout<<endl;
    
    return 0;
}
