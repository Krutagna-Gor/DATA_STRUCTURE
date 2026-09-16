#include<iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};
struct node *tos=NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=x;
    temp->next=NULL;
    return temp;
}
void push(int x)
{
  struct node *t;
  t=create_node(x);
  if(tos==NULL)
  {
    tos=t;
  }
  else
  {
    t->next=tos;
    tos=t;
  }
}
void pop()
{
    if(tos!=NULL){
    struct node *t;
    t=tos;
    t->next=tos;
    cout<<t->info<<" is poped!!";
    free(t);
    }
    else
    {
        cout<<"stack is empty!!";
    }
}
void display()
{
    if(tos!=NULL){
    struct node *t;
    t=tos;
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->next;
    }
}
else{
    cout<<"stack is empty!!";
}
}

int main()
{
    push(10);
    pop();
    return 0;
}