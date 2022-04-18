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
    void top();
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

void stack::top()
{
    if(count<0)
    {
        cout<<"stack is empty"<<endl;
    }
    else
        cout<<arr[count]<<" "<<endl;
}


int main()
{
    stack a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
    
    while (!a.isempty()) {
        a.top();
        a.pop();
    }
    a.top();
    a.push(999);
    a.top();
    
    return 0;
}
