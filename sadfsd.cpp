#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,count=0;
    cin>>x;
    if(x<3){cout<<0;return 0;}
    int arr[x],eo[x];
    for(int i=0;i<x;i++)
    {
        cin>>arr[i];
        //eo[i]=i<2?arr[i]:arr[i]+arr[i-2];
        //cout<<eo[i]<<" ";
    }
    /*for(int i=0;i<x;i++)
    {
        if(!i&&eo[x-1]-arr[0]==eo[x-2])count++;
        else if(i==x-1&&eo[x-1]==eo[x-2]-arr[i])count++;
        else
        {
            int s1=eo[x-1],s2=eo[x-2];
            s1= s1-(i&1?x&1?eo[i]:eo[i-1]:0);
            s2= s2-(i&1?x&1?eo[i-1]:eo[i]:0);
            if(s1==s2)count++;
        }
    }*/
    cout<<count;
    return 0;
}
//2 1 6 4
//2 1 8 5
