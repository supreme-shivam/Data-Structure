#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node()
    {
        data = NULL;
        next = NULL;
    }
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class solution
{
public:
    
    node* push_front(node* head, int x)
    {
        node* new_node = new node(x);
        if(head==NULL)
            return new_node;
        new_node->next = head;
        head = new_node;
        
        return head;
    }
    
    node* push_back(node* head, int x)
    {
        node* new_node = new node(x);
        if(head==NULL)
            return new_node;
        node* next = head;
        
        while(next->next!=NULL)
        {
            next = next->next;
        }
        next->next = new_node;
        
        return head;
    }
    
    node* push_after(node* head,int y,int x)
    {
        node* new_node = new node(x);
        node* next = head;
        
        while(next->data!=y)
        {
            next = next->next;
        }
        
        new_node->next =  next->next;
        next->next = new_node;
        
        return head;
    }
    
    node* push_before(node* head,int y,int x )
    {
        node* new_node = new node(x);
        node* next = head;
        node* temp = head;
        while(next->data!=y)
        {
            temp = temp->next;
            if(temp->data == y)
                break;
            next = next->next;
        }
        
        new_node->next = next->next;
        next->next = new_node;
        delete temp;
        
        return head;
    }
    
    node* push_beforee(node* head,int y,int x )
    {
        node* new_node = new node(x);
        node* change = head;
        while(change->next->data!=y)
        {
            change = change->next;
        }
        
        new_node->next = change->next;
        change->next = new_node;
        
        return head;
    }
    
    node* push_beforeee(node* head,int y,int x,int z)
    {
        int i;
        node* new_node = new node(x);
        node* change = head;
        node* change2 = head;
        
        for(i=0;i<z-1;i++)
        {
            change = change->next;
            if(change->data == y)
            {
                cout<<"Less members before "<<y<<endl;
                return head;
            }
        }
        int c = 0;
        while(change->data!=y)
        {
            change = change->next;
            if(c>1)
            change2 = change2->next;
            c++;
        }
        if(change->data == head->data)
        {
            head = push_front(head,x);
            return head;
        }
            
        
        new_node->next = change2->next;
        change2->next = new_node;
        
        return head;
    }
    
    node* push_afterr(node* head,int y,int x,int z)
    {
        int i;
        node* new_node = new node(x);
        node* change = head;
        node* change2 = head;
        for(i=0;i<z;i++)
        {
            
        }
        
        
        return head;
    }
    
    void print(node* head)
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    
    
};


int main()
{
    node* head = new node(1);
    
    solution obj;
    
    head = obj.push_back(head,2);
    head = obj.push_back(head,5);
    head = obj.push_back(head,8);
    obj.print(head);
    head = obj.push_front(head,0);
    obj.print(head);
    head = obj.push_back(head,10);
    head = obj.push_after(head,5,7);
    head = obj.push_beforee(head,5,3);
    head = obj.push_beforeee(head,5,13,0);
    
    obj.print(head);
    
    
    return 0;
}
