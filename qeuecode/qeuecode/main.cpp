#include<iostream>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
//    if(n==2)
//        return true;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int prime(int x)
{
    int i,count=0;
    for(i=2;i<=x;i++)
    {
        if(isPrime(i))
            count++;
    }
    return count;
}

int check(int x, int arr[])
{
    int count=0,i,j=0;
    
    if(x==2)
        return 1;
    
    for(i=2;i<x;i++)
    {
        if(i==arr[j])
        {
            count++;
            j++;
        }
    }
    return count;
}


int main()
{
    int o=10000,count=1,count2,i,count3,count4=0;
    count2 = prime(o);
    int arr[count2];
    arr[0] = 2;
    
    for(i=3;i<=o;i+=2)
    {
        if(isPrime(i))
        {
            arr[count] = i;
            count++;
        }
    }
    while(o!=1)
    {
        count3 = check(o,arr);
        o = o-count3;
        count4++;
    }
    
    cout<<count4<<endl;
    
    return 0;
}
