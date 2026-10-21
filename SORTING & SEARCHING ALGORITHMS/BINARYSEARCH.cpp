#include<iostream>
using namespace std;

int binary_search(int p[],int l,int r,int k)
{
    int mid;
    

    while(l<=r){
    mid=l+(r-l)/2;
    if(p[mid]==k)
    {
        return mid;
    }
    else if (p[mid]<k)
    {
        l=mid+1;
    }
    else
    {
        r=mid-1;
    }
}
    return -1;
}

int main()
{
    int n,p[100],key;
    cout<<"enter the nuber of element :";
    cin>>n;
    cout<<"\nenter numbers :\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"your entered elents are :";
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"which number you want to search through binary search?\n";
    cout<<"Enter key:";
    cin>>key;
    cout<<"\n\n----BINARY SEARCH----\n";
    int x=binary_search(p,0,n-1,key);
    if(x==-1)
    {
        cout<<"Invalid number!!!!";
    }
    else
    {
    cout<<"number is on position :"<<x+1;
    }
    return 0;
}