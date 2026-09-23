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
 temp=(struct node*)malloc(sizeof(struct node));
 temp->info=x;
 temp->next=NULL;
 return temp;
}
void insert_First(int x)
{
    struct node *t;
    t=create_node(x);
    if(first==NULL)
    {
     first=t;
    }
    else{
        t->next=first;
        first=t;
    }
}
void insert_Last(int x)
{
    struct node *y,*t;
    t=create_node(x);
    if(first==NULL)
    {
        first=t;
    }
    else{
        y=first;
        while(y->next!=NULL)
        {
            y=y->next;
        }
        y->next=t;
    }
}
void insert(int pos,int x)
{
  struct node *y,*t;
  int c=1;
  t=create_node(x);
  if(first==NULL)
  {
    first=t;
  }
  else{
    y=first;
    while(c!=pos-1){
      y=y->next;
      c++;
    }
    t->next=y->next;
    y->next=t;
  }
}
void insert_after_node(int x,int key)
{
    struct node *y,*t;
    t=create_node(x);
    if(first==NULL)
    {
        first=t;
    }
    else{
        y=first;
        while(y->info!=key)
        {
          y=y->next;
        }
        t->next=y->next;
        y->next=t;
    }
}
void display()
{
    if(first!=NULL)
    {
        struct node *temp;
        temp=first;
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
    }
    else{
        cout<<"There is no node in linked list!!!\n";
    }
}
void delete_first()
{
    struct node *t;
    t=first;
    first=first->next;
    free(t);
}
void delete_last()
{
    struct node *t,*y;
    t=first;
    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    y=t->next;
    t->next=y->next;
    free(y);
}
void delete_node(int pos)
{
    int c=1;
    struct node *t,*y;
    t=first;
    while(c!=pos-1)
    {
        t=t->next;
        c++;
    }
    y=t->next;
    t->next=y->next;
    free(y);
}
void delete_after_node(int key)
{
    struct node *t,*y;
    t=first;
    while(t->info!=key)
    {
        t=t->next;
    }
    y=t->next;
    t->next=y->next;
    free(y);
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
                insert_First(n);
                break;

                case 2:
                cout<<"Enter number which you want to insert :";
                cin>>n;
                insert_Last(n);
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