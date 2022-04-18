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
    int returncount();
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

int stack::returncount()
{
    return count+1;
}

int min(stack* s1,int x)
{
    if(s1->isempty())
        return x;
     x = s1->top();
    s1->pop();
    int y = min(s1,x);
    int z = x<y?x:y;
    s1->push(x);
    
    return z;
}


int main()
{
    stack s1;
    s1.push(-100);
    s1.push(80);
    s1.push(10);
    s1.push(70);
    s1.push(60);
    s1.push(75);
    s1.push(85);

    int r;
    r = min(&s1,s1.top());
    cout<<"Smallest : "<<r<<endl;

    while (!s1.isempty()) {
        cout<<s1.top()<<" ";
        s1.pop();
    }

    
    
    return 0;
}
