#include <iostream>
using namespace std;

void problem(int a[],int sp[],int s)
{
    sp[0] = 1;
    
    for(int i=1;i<s;i++)
    {
        int n = i-1;
        if (a[i]<a[n]) {
            sp[i] = 1;
            //n++;
            continue;
        }
        int count = 1;
        while(a[i]>a[n]&&n>0)
        {
            count++;
            n--;
        }
        sp[i] = count;
    }
}

int main()
{
    int price[] = { 100, 80, 60, 70, 60, 75, 85 };
    int s = sizeof(price)/sizeof(price[0]);
    int sp[s];
    
    problem(price,sp,s);
    
    for(int i=0;i<s;i++)
    {
        cout<<sp[i]<<" ";
    }
    
    
    return 0;
}
