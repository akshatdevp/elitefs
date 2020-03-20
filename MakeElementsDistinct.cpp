#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> m1;
    int n,x,y,t;
    cin>>n>>x>>y;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>t;
        m1[t]++;
    }
    int cost=0,tempcost=0;
    for(unordered_map<int,int>::iterator it=m1.begin();it!=m1.end();it++)
    {
        int c=(*it).second;
        int v=(*it).first;
        if(c<2)continue;
        while(c>1)
        {
            int v1=v;
            tempcost=y;
            while(m1.find(--v1)!=m1.end())tempcost+=y;
            if(tempcost>=x)cost+=x;
            else {m1[v1]++;cost+=tempcost;}
            c--;
            m1[v]=1;
            //cout<<tempcost<<" "<<cost<<endl;
        }
    }
    cout<<cost;
    return 0;
}
