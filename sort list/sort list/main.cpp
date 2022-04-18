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

node* sort(node* head)
{
    if(head==NULL || head->next == NULL)
        return head;
    node* temp = NULL;
    node* first = head;
    node* second = head->next;
    
    while(first->next!=NULL)
    {
        if(second->data < first->data)
        {
            head = swapnodes(head, first->data, second->data);
            temp = first;
            first = second;
            second = first;
        }
        
        second = second->next;
        
        if(second==NULL || first->next == NULL)
        {
            first = first->next;
            second = first->next;
        }
        
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

node* middle(node* head)
{
    node* first = head;
    node* second = head->next;
    
    while(first->next!=NULL && (second!=NULL && second->next !=NULL))
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

node* sort2(node* head)
{
    if(head->next == NULL)
        return head;
    
    node* mid;
    mid = middle(head);
    node* head2 = mid->next;
    mid->next = NULL;
    
    node* data = merge(sort2(head),sort(head2));
    
    
    return data;
}
 


int main()
{
    
    
    node* a1 = NULL;
    
    a1 = push_back(a1,5);
    a1 = push_back(a1,10);
    a1 = push_back(a1,51);
    a1 = push_back(a1,33);
    a1 = push_back(a1,77);
    a1 = push_back(a1,60);
    a1 = push_back(a1,21);
    a1 = push_back(a1,2);
    
    cout<<"Before sort : ";
    printList(a1);
    cout<<endl;
    a1 = sort(a1);
    cout<<"After sort : ";
    printList(a1);
    cout<<endl;
    a1 = sort2(a1);
    cout<<"After sort2 : ";
    printList(a1);
    cout<<endl;
    
    
    return 0;
}
