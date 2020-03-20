#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,count=0;
    cin>>x;
    int arr[x],eo[x];
    for(int i=0;i<x;i++)
    {
        cin>>arr[i];
        eo[i]=i>1?eo[i-2]+arr[i]:arr[i];
    }
    if(x<3){cout<<0;return 0;}
    bool o;
    if(x&1)o=true; else o=false;
    for(int i=0;i<x;i++)
    {
        int s1=eo[x-1];
        int s2=eo[x-2];
        bool io=i&1;
        if(!(o^io))
            {
            if((i==0||i==x-1)&&s2-arr[i]==s1)count++;
            else if(i>1&&s2-eo[i]+eo[i-1]==s1-eo[i-1]+eo[i-2])count++;
            }
        else 
        {
            if((i==0||i==x-1)&&s1-arr[i]==s2)count++;
            else if(s1-eo[i]+(i>0?eo[i-1]:0)==s2-(i>0?eo[i-1]:0)+(i>1?eo[i-2]:0))count++;
        }
    }
    cout<<count;
    return 0;
}
// 5 6 2 5  8
// 5 6 7 11 15
// o&&i, or !i&&!o = 
// del 2 array becomes 5 6 5  8 
//                     5 6 10 14 
