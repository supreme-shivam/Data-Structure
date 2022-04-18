//example = {()}[]
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
    cout<<"Enter : ";
    getline(cin, a);
    unsigned long i = a.length();
    int count1=0,count2=0,count3=0;
    
    //while(a[i]!=NULL)
    for(int n=0;n<i;n++)
    {
        if(a[n]==40)
        {
            s1.push(a[n]);
            count1++;
        }
        else if(a[n]==91)
        {
            s1.push(a[n]);
            count2++;
        }
        else if(a[n]==123)
        {
            s1.push(a[n]);
            count3++;
        }
        else if(a[n]==41)
        {
            s1.pop();
            count1--;
        }
        else if(a[n]==93)
        {
            s1.pop();
            count2--;
        }
        else if(a[n]==125)
        {
            s1.pop();
            count3--;
        }
//        else if(a[n]==32)
//        {
//        }
        
    }
    if(count1>0)
        cout<<count1<<" ')' not closed : Not Balanced"<<endl;
    if(count2>0)
        cout<<count2<<" ']' not closed : Not Balanced"<<endl;
    if(count3>0)
        cout<<count3<<" '}' not closed : Not Balanced"<<endl;
    if(count1==0 && count2==0 && count3==0)
        cout<<"Balanced"<<endl;
    
    
    return 0;
}

