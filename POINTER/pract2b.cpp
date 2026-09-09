#include<iostream>
using namespace std;
void swap_by_value(int x,int y)
{
    int temp =x;
    x=y;
    y=temp;
}
void swap_by_reference(int *x,int *y)
{
        int temp= *x;
        *x=*y;
        *y =temp;
}
int main()
{
    int a=10,b=20;
    cout<<"Before swap by value a="<<a<<" & b="<<b<<endl;
    swap_by_value(a,b);
    cout<<"After swap by value a="<<a<<" & b="<<b<<endl;
    cout<<"Before swap by reference a="<<a<<" & b="<<b<<endl;
    swap_by_reference(&a,&b);
    cout<<"After swap by reference a="<<a<<" & b="<<b<<endl;
    return 0;
}