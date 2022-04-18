//example1 100 200 + 2 / 5 * 7 +
//example2 2 3 1 * + 9 -
#include<iostream>
using namespace std;

#define full 1000

class stack
{
    int count;
    int count2;
public:
    int arr[full];
    stack(){count = -1;count2 = full/2;};
    void push(int);
    void pop();
    void top();
    void push2(int);
    void pop2();
    void top2();
    bool isempty();
};

void stack::push(int x)
{
    if(count>full/2)
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
    {
        cout<<arr[count]<<endl;
        arr[count--] = NULL;
    }
}

bool stack::isempty()
{
    return (count<0);
}

void stack::top()
{
    if(count<0)
    {
        return;
    }
    else
    cout<<arr[count];
}

void stack::push2(int x)
{
    if(count2>full)
    {
        cout<<"stack overflow!";
        return;
    }
    else
        arr[++count2] = x;
}

void stack::pop2()
{
    if(count2<(full/2)+1)
    {
        cout<<"stack underflow!";
        return;
    }
    else
    {
        cout<<arr[count2]<<endl;
        arr[count2--] = NULL;
    }
}

void stack::top2()
{
    if(count2<(full/2)+1)
    {
        return;
    }
    else
    cout<<arr[count2];
}

int main()
{
    stack s;
    s.push(5);
    s.push2(10);
    s.push2(15);
    s.push(11);
    s.push2(7);
    cout<<"Popped element from stack1 is ";
    s.pop();
    s.push2(40);
    cout<<"\nPopped element from stack2 is ";
    s.pop2();
    s.push2(999);
    s.top2();
    
    
    
    return 0;
}
