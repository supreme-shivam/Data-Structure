//example1 100 200 + 2 / 5 * 7 +
//example2 2 3 1 * + 9 -
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

int convert(char x)
{
    if(x>=48 && x<=57)
    {
        return x-48;
    }
    else
        return NULL;
}


int main()
{
    stack s1;
    string a;
    cout<<"Enter postfix : ";
    getline(cin, a);
    unsigned long i = a.length();
    
    //while(a[i]!=NULL)
    for(int n=0;n<i;n++)
    {
        if(a[n]>=48 && a[n]<=57)
        {
            int sum = 0;
            while(a[n]!=32)
            {
                int x = convert(a[n]);
                sum = sum*10 + x;
                n++;
            }
            s1.push(sum);
        }
        else if(a[n]==42)
        {
            int x = s1.top();
            s1.pop();
            int y = s1.top();
            s1.pop();
            s1.push(y*x);
        }
        else if(a[n]==43)
        {
            int x = s1.top();
            s1.pop();
            int y = s1.top();
            s1.pop();
            s1.push(y+x);
        }
        else if(a[n]==45)
        {
            int x = s1.top();
            s1.pop();
            int y = s1.top();
            s1.pop();
            s1.push(y-x);
        }
        else if(a[n]==47)
        {
            int x = s1.top();
            s1.pop();
            int y = s1.top();
            s1.pop();
            s1.push(y/x);
        }
        else if(a[n]==32)
        {
        }
        else
        {
            cout<<"Wrong Input";
            return 0;
        }
        
    }
    cout<<"Evaluation result : "<<s1.top()<<endl;
    
    
    return 0;
}
