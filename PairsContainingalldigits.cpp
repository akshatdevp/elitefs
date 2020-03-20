#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)
    {
        string s1;
        cin>>s1;
        arr[i]=0;
        for(int j=0;j<s1.size();j++)
            arr[i] |= (1<<(s1[j]-'0'));
    }
    int count=0;
    for(int i=0;i<x-1;i++)
    {
        for(int j=i+1;j<x;j++)
        {
            if(__builtin_popcount(arr[i]|arr[j])==10)count++;
        }
    }
    cout<<count;
    return 0;
}
