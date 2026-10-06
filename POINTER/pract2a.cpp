#include<iostream>
using namespace std;
int main()
{
    int *p,n;
    int x[10];
    p=x;
    cout<<"enter the number of elements(1 to 10) which you want to insert in array :- ";
    cin>>n;
    cout<<"enter the elements :-\n";
    for(int i=0;i<n;i++)
    {
        cin>>*p;
        p++;
    }
    p--;
    for(int i=n-1;i>=0;i--)
    {
        cout<<*p<<" ";
        p--;
    }
    return 0;
}