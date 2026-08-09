#include<iostream>
using namespace std;
int main()
{
    int s;
    char ch;
    cout<<"Enter the size_number of list :"<<endl;
    cin>>s;
    int list[s];
    int key,found=0;
    int n,count=0,number,position,choice;
    cout<<"Enter the number of element of list under a size "<<s<<" :"<<endl;
    cin>>n;
    if(n>s){
      cout<<"invalid elements!!!";
      return 0;
    }
    cout<<"Enter numbers :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>list[i];
        count++;
    }
  
    do{
        cout<<"enter choice : 1.insertion 2.deletion  3.search  4.display 5.number_of_elements\n ";
        cout<<"choice :";
        cin>>choice;
        switch(choice)
        {
           case 1:
               cout<<"Enter number & position which you insert into the list :"<<endl;
               cout<<"position :"<<endl;
               cin>>position;
    cout<<"number :"<<endl;
    cin>>number;
    if(position==n+1)
    {
     list[position-1]=number;
     n++;
     count++;
    }
    else if(position>n+1)
    {
        cout<<"invalid position!!!";
        break;
    }
    else{

    for(int i=n-1;i>=position-1;i--)
    {
      list[i+1]=list[i];
    }
     list[position-1]=number;
     n++;
     count++;
    }
    break;

     case 2:
     int pos;
     cout<<"enter a position between(1 t0 "<<n << ") which you want to DELETE :";
     cin>>pos;
     for(int i=pos-1;i<n-1;i++)
     {
        list[i]=list[i+1];
     }
     n--;
     count--;
     break;
      
     case 3:
     
     cout<<"Enter element to search :"<<endl;
     cin>>key;
     for(int i=0;i<n;i++){
        if(list[i]==key)
        {
            cout<<"element found at position of "<<i+1<<endl;
             found=1;
             break;
        }
       }
       if(found==0)
       {
        cout<<"element not found!!!!"<<endl;
       }
       break;

       case 4:
    for(int i=0;i<n;i++)
    {
        cout<<list[i]<<endl;
    }
    break;

    case 5:
    cout<<"Now,number of element in  the list is "<<count<<endl;
    break;

     }
     cout<<"\nDo you want to continue ?\nyes/no ?\nif yes enter 'Y' or if no then 'N' "<<endl;
     cin>>ch;
    }while(ch=='Y');
 return 0;
}