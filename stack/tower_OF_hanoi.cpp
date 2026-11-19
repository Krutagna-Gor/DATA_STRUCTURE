#include<iostream>
using namespace std;

void towerOfhanoi(int n,char source,char helper,char destination)
{
    if(n==1)
    {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        return;
    }

    towerOfhanoi(n - 1, source, destination, helper);

    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    towerOfhanoi(n - 1, helper, source, destination);
}

int main()
{
    int n;

    cout<<"Enter number of disks :";
    cin>>n;

    towerOfhanoi(n,'A','B','C');

    return 0;
}