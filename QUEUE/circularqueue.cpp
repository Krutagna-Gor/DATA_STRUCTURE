#include<iostream>
using namespace std;
#define s 20
int queue[s];
int front=-1,rear=-1;
int full()
{
    if((rear+1)%s==front)
    return 1;
    else
    return 0;
}
int empty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    return 0;
}
void Enqueuer(int x)
{
    if(full())
    {
        cout<<"Queue is full !!!!!\nyou can not enqueuer !!!!";
        
    }
    else
    {
        if(front==-1)
        {
          front=0;
        }
        rear=(rear+1)%s;
        queue[rear]=x;
    }
}
int Dequeuer()
{
    int x;
    if(!empty())
    {
        x=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
            cout<<"!!!----circular queue----!!!\n";
        }
        else
        front=(front+1)%s;
        cout<<x<<" is Dequeuer(delete) from queue...\n";
    }
    else
    {
        cout<<"Bhai!!!..\nqueue to khali chhe !!!\n delete karavu j possible nathi ....";
        return 1;
    }
    return x;
}
void display()
{
    for(int i=front;i<=rear;i=(i+1)%s){
        cout<<queue[i]<<" ";
        if(i==rear)
        {
            break;
        }
        
    }
    
}

int main()
{
    int count=0;
    int c,choice;
    do{
         cout<<"Enter choice to perform queue operations :-\n1.Enqueuer(insert) 2.Dequeuer(delete) 3.display\n\nchoice :- ";
         cin>>choice;
        switch(choice)
        {
            case 1:
            int n;
            cout<<"Enter the element which you want to Enqueuer(insert) :-\n";
            cin>>n;
            Enqueuer(n);
            count++;
            break;

            case 2:
            int x;
            x=Dequeuer();
            
            
            break;

            case 3:
            display();
            cout<<"\n";
            break;
            
            default :
            cout<<"invalid choice :";
            break;
        }
        cout<<"\nif you want to continue then enter 1 else enter 2 :-\nchoice :- ";
        cin>>c;
        
    }while(c==1);
   return 0;
}