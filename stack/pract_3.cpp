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


int main()
{
    
    int choice,n,ch,x;
    do{  
        cout<<"enter choice that which operation you want to on stack :\n(1.push 2.pop 3.peek 4.display)"<<endl<<"choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter the element which you want to push :"<<endl;
            cin>>n;
            push(n);
            break;

            case 2:
            x=pop();
            cout<<x<<endl;
            break;

            case 3:
            x = peep();
            cout<<x<<endl;
            break;

            case 4:
            display();
            break;
        }
        cout<<"do you want to continue?\nif yes then enter '1' and if no then enter '2' :";
        cin>>ch;
    }while(ch==1);
  return 0;
}