#include<iostream>
using namespace std;
#define s 20
int tos=-1;
int stk[s];

  void push(int x)
  {
    if(tos>=s)
    {
        cout<<"stack is full!!!! \nyou can not push the element into the stack!!!\n";
        
    }
    else
    {
        ++tos;
        stk[tos]=x;
    }
  }
  int pop(void)
  {
    int x;
    if(tos>-1)
    {
     x=stk[tos];
     tos--;
     return x;
    }
    else
    {
        cout<<"the stack is empty!!!";
        return 1;
    }
  }
  int peep(void)
  {
    int x;
    if(tos>-1)
    {
        x=stk[tos];
        return x;
    }
    else
    {
        cout<<"stack is empty!!!"<<endl;
        return 1;
    }
  }
    void display()
  {
    if(tos>-1)
    {
        for(int i=0;i<=tos;i++)
        {
            cout<<stk[i]<<"\n";
        }
    }
    else
    {
        cout<<"the stack is empty!!!\n";
        
    }
  }