#include<bits/stdc++.h>
using namespace std;
int main()
{
 int arr[100],x=0;
    while(cin>>arr[x++]);
    int a1=-1,a2=-1,a3=-1;
    for(int i=0;i<x;i++)
    {
        if(a1==-1||arr[a1]<=arr[i]) a3=a2,a2=a1,a1=i;
        else if(a2==-1||arr[a2]<=arr[i]) a3=a2,a2=i;
        else if(a3==-1||arr[a3]<=arr[i]) a3=i;
    }
if(a3==-1)
cout<<arr[a1];
else cout<<arr[a3];
}