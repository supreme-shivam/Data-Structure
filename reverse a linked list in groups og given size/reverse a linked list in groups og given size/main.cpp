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

node* swapnodes(node*,int,int);

node* reverse(node* head,int x)
{
    node* first = head;
    node* second = head;
    node* temp = NULL;
    
    while(first->next!=NULL || second->next!=NULL)
    {
        for(int i = 1; i < x; i++)
        {
            if(second->next==NULL)
                break;
            second = second->next;
        }
        if(first->next==NULL||second->next==NULL)
        {
            head = swapnodes(head, first->data, second->data);
            break;
        }
        head = swapnodes(head, first->data, second->data);
        temp = first;
        first = first->next;
        second = first;
    }
    
    return head;
}


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


int main()
{
    
    
    node* a1 = NULL;
    
    a1 = push_back(a1,1);
    a1 = push_back(a1,2);
    a1 = push_back(a1,3);
    a1 = push_back(a1,4);
    a1 = push_back(a1,5);
    a1 = push_back(a1,6);
    a1 = push_back(a1,7);
    a1 = push_back(a1,8);
    
    cout<<"Before reverse : ";
    printList(a1);
    cout<<endl;
    a1 = reverse(a1,5);
    cout<<"After reverse : ";
    printList(a1);
    cout<<endl;
    
    
    return 0;
}
