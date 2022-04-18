#include<iostream>
using namespace std;

#define full 1000

class stack
{
    int count;
public:
    int arr[full];
    stack(){count = -1;};
    void push(int);
    void pop();
    int top();
    bool isempty();
};

void stack::push(int x)
{
    if(count>full-1)
    {
        cout<<"stack overflow!";
        return;
    }
    else
        arr[++count] = x;
}

void stack::pop()
{
    if(count<0)
    {
        cout<<"stack underflow!";
        return;
    }
    else
        arr[count--] = NULL;
}

bool stack::isempty()
{
    return (count<0);
}

int stack::top()
{
    if(count<0)
    {
        return NULL;
    }
    
    return arr[count];
}

void reverse2(stack* s1,int e)
{
    if(s1->isempty())
        s1->push(e);
    else
    {
        int x = s1->top();
        s1->pop();
        reverse2(s1,e);
        s1->push(x);
    }
}

void reverse(stack* s1)
{
    if(s1->isempty())
        return;
    int x = s1->top();
    s1->pop();
    reverse(s1);
    //s1->push(x);
    reverse2(s1,x);
}


int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    
    reverse(&s1);
    
    while(!s1.isempty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    
    
    return 0;
}

