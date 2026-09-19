#include<iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};
struct node *first=NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=x;
    temp->next=NULL;
    return temp;
}
void insert_first(int x)
{
    
    struct node *temp,*t;
    t=create_node(x);
    if(first!=NULL){
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    temp->next=t;
    t->next=first->next;
    first=t;
}
else{
    first=t;
    t->next=first;
}
}
void insert_last(int x)
{
    struct node *temp,*t;
    t=create_node(x);
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
}
void insert(int x,int pos)
{
    struct node *temp,*t;
    int c=1;
    t=create_node(x);
    if(first!=NULL){
    temp=first;
    while(c!=pos-1)
    {
        temp=temp->next;
        c++;
    }
    t->next=temp->next;
    temp->next=t;
}
else{
    first=t;
    t->next=first;
}
}
void insert_after_node(int x,int key)
{
    struct node *temp,*t;
    t=create_node(x);
    if(first!=NULL){
    temp=first;
    while(temp->info!=key)
    {
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
}
else{
    first=t;
    t->next=first;
}
}
void delete_first()
{
    struct node *temp,*t;
    temp=t=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    first=first->next;
    temp->next=first;
    free(t);
}
void delete_last()
{
    struct node *temp,*t;
    t=first;
    while(t->next->next!=first)
    {
        t=t->next;
    }
    temp=t->next;
    t->next=temp->next;
    free(temp);
}
void delete_node(int pos)
{
    int c=1;
    struct node *temp,*t;
    t=first;
    while(c!=pos-1)
    {
        t=t->next;
        c++;
    }
    temp=t->next;
    t->next=temp->next;
    free(temp);
}
void delete_after_node(int key)
{
    struct node *temp,*t;
    t=first;
    while(t->info!=key)
    {
        t=t->next;
    }
    temp=t->next;
    t->next=temp->next;
    free(temp);
}
void display()
{
    if(first!=NULL){
    struct node *temp;
    temp=first;
   do
   {
        cout<<temp->info<<"\n";
        temp=temp->next;
   }while(temp!=first);
   }
   else
   {
      cout<<"\nlist is empty!!!\n";
   }
}
int main()
{
    int c,n,choice,count=0;
    do
    {
        cout<<"Enter singly linked list operation :\n1.insert 2.delete 3.display\n\nchoice:-";
        cin>>choice;
        switch(choice)
        {
            case 1:
            int C;
            cout<<"select where you want to insert:\n1.at first 2.at last 3.at any node 4.at after given node\n\nchoice:-";
            cin>>C;
             switch(C)
             {
                case 1:
                cout<<"Enter number which you want to insert :";
                cin>>n;
                insert_first(n);
                break;

                case 2:
                cout<<"Enter number which you want to insert :";
                cin>>n;
                insert_last(n);
                break;
                
                case 3:
                int pos;
                cout<<"Enter number & position which you want to insert :\n";
                cout<<"number :";
                cin>>n;
                cout<<"\nposition :";
                cin>>pos;
                insert(pos,n);
                break;
           
                case 4:
                int key;
                cout<<"Enter number  which you want to insert :\n";
                cout<<"number :";
                cin>>n;
                cout<<"\nEnter content of node which you want to insert after node :\ncontent:";
                cin>>key;
                insert_after_node(n,key);
                break;

                default:
                cout<<"\ninvalid choice!!!";
             }
             break;
             
             case 2:
             int Ch;
             cout<<"select option of node for delete:\n1.first 2.last 3.at any node 4.at after given node\n\nchoice:-";
             cin>>Ch;
             switch(Ch)
             {
                case 1:

                delete_first();
                break;

                case 2:
                delete_last();
                break;
                
                case 3:
                int pos;
                cout<<"Enter postion which you want to delete :\n";
                cout<<"\nposition :";
                cin>>pos;
                delete_node(pos);
                break;
           
                case 4:
                int key;
                cout<<"\nEnter content of node which you want to delete after node :\ncontent:";
                cin>>key;
                delete_after_node(key);
                break;

                default:
                cout<<"\ninvalid choice!!!";
             }
             break;

             case 3:
             display();
             break;

             default:
             cout<<"\ninvalid choice!!!";            
        } 
        cout<<"\nSelect :-\nFor continue : 1\nFor exit : 2\n";
        cin>>c;
    }while(c==1);
    return 0;
}