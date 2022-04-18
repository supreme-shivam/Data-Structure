#include<iostream>
using namespace std;

char box[10] = {'0','1','2','3','4','5','6','7','8','9'};

void show()
{
    cout<<" "<<box[1]<<" | "<<box[2]<<" | "<<box[3]<<endl;
    cout<<" ----------"<<endl;
    cout<<" "<<box[4]<<" | "<<box[5]<<" | "<<box[6]<<endl;
    cout<<" ----------"<<endl;
    cout<<" "<<box[7]<<" | "<<box[8]<<" | "<<box[9]<<endl;
}

void inpu(int inp,char sign)
{
    int x=1,y=0;
    while(x==1)
    {
        if(y>0)
            cin>>inp;
    switch (inp) {
        case 1:
            if(box[1]=='1')
            {
                box[1] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 2:
            if(box[2]=='2')
            {
                box[2] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 3:
            if(box[3]=='3')
            {
                box[3] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 4:
            if(box[4]=='4')
            {
                box[4] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 5:
            if(box[5]=='5')
            {
                box[5] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 6:
            if(box[6]=='6')
            {
                box[6] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 7:
            if(box[7]=='7')
            {
                box[7] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 8:
            if(box[8]=='8')
            {
                box[8] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
        case 9:
            if(box[9]=='9')
            {
                box[9] = sign;
                x = 0;
            }
            else{
                cout<<"Wrong Input Enter Again : ";y++;
            }
            break;
            
        default:
            cout<<"Wrong Input Enter Again : ";y++;
            break;
    }
    }
    return;
}

int check()
{
    if (box[1]==box[2] && box[2]==box[3]) {
        return 1;
    }
    else if (box[1]==box[5] && box[5]==box[9]) {
        return 1;
    }
    else if (box[1]==box[4] && box[4]==box[7]) {
        return 1;
    }
    else if (box[2]==box[5] && box[5]==box[8]) {
        return 1;
    }
    else if (box[4]==box[5] && box[5]==box[6]) {
        return 1;
    }
    else if (box[3]==box[6] && box[6]==box[9]) {
        return 1;
    }
    else if (box[7]==box[8] && box[8]==box[9]) {
        return 1;
    }
    else if (box[3]==box[5] && box[5]==box[7]) {
        return 1;
    }
    else
    return 0;
    
    return 0;
}

int main()
{
    int inp,player=1,flag=0,counter = 0;
    char sign = 'X';
    
    while(flag!=1&&counter<9)
    {
    show();
    cout<<endl<<"player "<<player<<" Choose any given no : ";
    cin>>inp;
    inpu(inp,sign);
    flag = check();
    if(flag == 1)
    {
        show();
        cout<<"Player "<<player<<" is the winner"<<endl;
        return 0;
    }
    if(player==1)
        player=2;
    else if (player==2)
        player=1;
    if(sign=='X')
        sign='O';
    else if (sign=='O')
        sign='X';
        counter++;
    }
    show();
    cout<<endl<<"DRAW! ;)"<<endl;
    return 0;
}
