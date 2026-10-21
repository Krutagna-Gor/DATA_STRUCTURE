#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *next,*prev;
};
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=x;
    temp->next=NULL;
    temp->prev=NULL;
    return(temp);
}
struct node *first=NULL,*last=NULL;
void insert(int pos, int x)
{
    struct node *temp,*y;
    temp=create_node(x);
    if(first==NULL)
    {
        first=temp;
        last=temp;
    }
    else
    {
        int c=1;
        y=first;
        while(c!=pos-1)
        {
            y=y->next;
            c++;
        }
        temp->next=y->next;
        y->next->prev=temp;
        temp->prev=y;
        y->next=temp;
    }
}
void delete_node(int pos)
{
    int c=1;
    struct node *temp,*t;
    while(c!=pos-1)
    {
        temp=temp->next;
        c++;
    }
    t=temp->next;
    temp->next=t->next;
    t->next->prev=t->prev;
    free(t);
}

void display(int x)
{
    if(first!=NULL)
    {
        if(x==1)
        {
            struct node *temp;
            temp=first;
            while(temp!=NULL)
            {
                cout<<temp->info<<" ";
                temp=temp->next;
            }
        }
        else
        {
            struct node *temp;
            temp=last;
            while(temp!=NULL)
            {
                cout<<temp->info<<"";
                temp=temp->prev;
            }
        }
    }
    else
    {
        cout<<"List is empty!!!";
    }
}

int main()
{
    int choice;
    do
    {
        cout<<"========doubly linked list========\n";
        cout<<"1.insertion\n";
        cout<<"2.deletion\n";
        cout<<"3.display\n";
        cout<<"Enter choice: \n";
        cin>>choice;

        switch(choice)
        {
            case 1:

            int x,pos;
            cout<<"Enter a position where you want to insert :\n "
            cin>>pos;
            cout<<"Enter the number which you want to insert :\n";
            cin>>x;
            
            insert(pos,x);
            break;

            case 2:

            int pos;
            cout<<"Enter a position where you want to delete :\n "
            cin>>pos;

            delete_node();
            break;

            case 3:
            int c;
            cout<<"Enter choice how you want to display :\n";
            cout<<"1.Left to right\n";
            cout<<"2.Right to left\n";
            cout<<"Enter choice\n";
            cin>>c;
            if(c=1)
            {
                cout<<"====NORMAL====\n";
                display(c);
            }
            else
            {
                cout<<"====REVERSE====\n";
                display(c);
            }
            break;

            default:
            cout<<"\nInavalid choice!!!\n";
            break;
        }
        
        cout<<ch;
        cout<<"\nIf you want to continue :\n";
        cout<<"YES : Enter '1";
        cout<<"NO : Enter '2";
        cin>>ch;
    }while(ch==1)
}