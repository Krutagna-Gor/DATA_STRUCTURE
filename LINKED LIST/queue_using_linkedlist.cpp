#include<iostream>
using namespace std;

struct node 
{
    int info;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=x;
    temp->next=NULL;
    return temp;
}
void insert(int x)
{
    struct node *t,*y;
    t=create_node(x);
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        y=front;
        while(y->next!=NULL)
        {
            y=y->next;
        }
        rear=t;
        y->next=t;
    }
}
void dequeue()
{
    if(front!=NULL){
    struct node *t;
    t=front;
    front=front->next;
    free(t);
    }
    else{
        cout<<"queue is empty!!\n";
    }
}
void display()
{
    if(front!=NULL)
    {
    struct node *t=front;
    
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->next;
    }
    }
    else
    {
        cout<<"queue is empty!!\n";
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    dequeue();
    display();

}