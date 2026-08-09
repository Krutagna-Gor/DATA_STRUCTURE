#include<iostream>
#include<string.h>
#include<math.h>
#include"stack.h"
using namespace std;
int prec(char c)
{
    if(c=='$'){
        return 3;
    }
    else if(c=='*'||c=='/')
        return 2;
    
    else if(c=='+'||c=='-'){
        return 1;
    }
    else
    return -1;   
}

int main()
{
    string infix;
    cout<<"Enter the infix expression which you want to evalute into postfix :";
    cin>>infix;
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='(')
        {
           push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(tos>-1 && peep()!='(')
            {
                postfix+=peep();
                pop();
            }
            if(tos>-1)
            {
                pop();
            }
            
        }
        else
        {
            while(tos>-1 && prec(peep())>prec(infix[i]))
            {
               
               postfix+=peep();
               pop(); 
            }
            push(infix[i]);
        }
        
    }
    while(tos>-1)
    {
        postfix+=peep();
        pop();
    }
    cout<<"Infix to Postfix :- "<<postfix;
    return 0;
}