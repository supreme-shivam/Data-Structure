#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;
public:
    stack(){data=NULL;next=NULL;}
//    void push(stack*,int);
//    void pop(stack*);
//    void top();
//    bool isempty();
};

void push(stack** head,int x)
{
    if(*head == NULL)
    {
        *head = new stack();
        (*head)->data = x;
        (*head)->next = NULL;
        return;
    }
    
    stack *a = new stack();
    a->data = x;
    a->next = *head;
    *head = a;
}

void pop(stack** head)
{
    if(*head == NULL)
    {
        cout<<"empty stack!"<<endl;
        return;
    }
    stack *a = *head;
    *head = (*head)->next;
    free(a);
}

bool isempty(stack * head)
{
    return (head==NULL);
}

void top(stack* head)
{
    if(head!=NULL)
    cout<<head->data<<endl;
    else
        cout<<"stack empty"<<endl;
    
}

int main()
{
    stack *s1=NULL;
    push(&s1,10);
    push(&s1,20);
    push(&s1,30);
    push(&s1,40);
    //pop(&s1)
    
    while(!isempty(s1))
    {
        cout<<s1->data<<endl;
        pop(&s1);
    }
    
    pop(&s1);
    top(s1);
    
    return 0;
}
