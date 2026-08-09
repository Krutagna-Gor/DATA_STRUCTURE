#include<iostream>
#include<string.h>
#include<math.h>
#include"stack.h"
using namespace std;
int cal(char op,int op1,int op2)
{

  int result;
  switch(op)
  {
    case '+':
    result=op1+op2;
    return result;
    break;
    
    case '-':
    result=op1-op2;
    return result;
    break;

    case '*':
    result=op1*op2;
    return result;
    break;
    case '/':
    result=op1/op2;
    return result;
    break;

    case '$':
    result=pow(op1,op2);
    return result;
    break;

  }

}
int main()
{
  string post{50};
  int op1,op2,result;
  cout<<"Enter the prefix expression which you want to evaluate :"<<endl;
  cin>>post;
  
  for(int i=post.length()-1;i>=0;i--)
  {
    if(isdigit(post[i]))
    {
      push(post[i]-'0');
    }
    else{
      op1=pop();
      op2=pop();
      result=cal(post[i],op1,op2);
      push(result);
    }
  }
  int x=pop();
  cout<<"prefix evaluation : "<<x;
  return 0;
}