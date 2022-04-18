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

int problem2(stack*s1,int x)
{
    int count=0;
    if(x>s1->top())
    {
        count++;
        int y = s1->top();
        s1->pop();
        if(s1->isempty())
        {
            s1->push(y);
            return 1;
        }
        count = count + problem2(s1,x);
        s1->push(y);
        return count;
    }
    else
        return 1;
    
    
    return 1;
}

void problem(stack* s1,int arr[],int n)
{
    if(s1->isempty())
        return;
    for(int i=n-1;i>=0;i--)
    {
        int x = s1->top();
        s1->pop();
        if(s1->isempty())
        {
            arr[i]=1;
            return;
        }
        arr[i]=problem2(s1,x);
        //n--;
    }
}


int main()
{
    stack s1;
    s1.push(100);
    s1.push(80);
    s1.push(60);
    s1.push(70);
    s1.push(60);
    s1.push(75);
    s1.push(85);
    
    int n = s1.returncount();
    int arr[n];
    problem(&s1, arr, n);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
