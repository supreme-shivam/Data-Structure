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

void detect(node* head)
{
        node* head1 = new node(8);
}

void detect2(node* head)
{
    node* forward = head;
    node* slow = head;
    
    while(forward!=NULL&&forward->next!=NULL)
    {
        forward = forward->next->next;
        slow = slow->next;
        if (forward==NULL) {
            cout<<"Not in loop"<<endl;
            return;
        }
        if(forward->next == slow->next)
        {
            cout<<"In a loop"<<endl;
            forward->next = NULL;
            printList(head);
            return;
        }
    }
    cout<<"Not in a loop"<<endl;
    
}

int main()
{
    
    node* a1 = new node(1);
    node* a2 = new node(2);
    node* a3 = new node(3);
    node* a4 = new node(4);
    node* a5 = new node(5);
    node* a6 = new node(6);
    
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    a6->next = a3;
    
    
    detect2(a1);
    
    //cout<<a1<<endl;
//    cout<<"Before reverse : ";
//    printList(a1);
//    cout<<endl;
//
//    cout<<"After reverse : ";
//    printList(a1);
//    cout<<endl;
    
    
    return 0;
}
