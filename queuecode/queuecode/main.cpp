#include<iostream>
using namespace std;

int main()
{
    int x=2,y=4,n=14,flag1=0,flag2=0;
    float data[n];
    //4.55 5.4 5.65 5.4 5.2 4.85 4.95 5.05 4.9 4.9 4.95
    //69.849998 72.900002 74.449997 77.300003 75.050003 74.349998 75.449997 76.300003 74 69.349998 65.349998 67.349998 67.599998 68.449997
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    float arrx[n],arry[n];
    
    for(int j=x-1;j<n;j++)
    {
        arrx[j] = (data[j]+data[j-1]+data[j-2])/3;
        cout<<j<<"= "<<arrx[j]<<" ";
    }
    
    cout<<endl;
    
    for(int i=y-1;i<n;i++)
    {
        arry[i] = (data[i]+data[i-1]+data[i-2]+data[i-3]+data[i-4])/5;
        cout<<i<<"= "<<arry[i]<<" ";
    }
    
    cout<<endl;
    
    for(int m=y-1;m<n;m++)
    {
        if(arrx[m]>arry[m] && arrx[m]>arry[m])
            flag1++;
        else
            flag2++;
    }
    
    cout<<flag1-flag2;
    cout<<endl;
    
    
    
    
    
    return 0;
}
