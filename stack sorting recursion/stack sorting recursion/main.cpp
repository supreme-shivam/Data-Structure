#include<iostream>
using namespace std;

#define max 100
class stack
{
    int count;
public:
    int arr[max];
    stack(){count = -1;}
    void push(int);
    void pop();
    int top();
    bool isempty();
};

void stack::push(int a)
{
    if(count>max-1)
    {
        cout<<"stack overflow";
        return;
    }
    arr[++count] = a;
}

void stack::pop()
{
    if(count<0)
    {
        cout<<"stack underflow";
        return;
    }
    count--;
}

int stack::top()
{
    return arr[count];
}

bool stack::isempty()
{
    return (count<0);
}

void sort3(stack* s1,int x)
{
    if(s1->top()>x)
    {
        int y = s1->top();
        s1->pop();
        if(s1->isempty())
        {
            s1->push(x);
            s1->push(y);
            return;
        }
        sort3(s1,x);
        s1->push(y);
    }
    else
        s1->push(x);
}


void sort2(stack* s1,int x)
{
    if(s1->isempty())
    {
        s1->push(x);
        return;
    }
    sort3(s1,x);
    
}

void sort(stack* s1)
{
    if(s1->isempty())
        return;
    int x = s1->top();
    s1->pop();
    sort(s1);
    sort2(s1,x);
}


int main()
{
    stack s1;
    s1.push(-2);
    s1.push(3);
    s1.push(1);
    s1.push(40);
    s1.push(20);
    
    sort(&s1);
    
    
    while(!s1.isempty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    
    return 0;
}
