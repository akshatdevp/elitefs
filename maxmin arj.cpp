#include<bits/stdc++.h>
using namespace std;
//algorithm: binary search for optimal answer
int find(vector<int> arr,int l,int r,int s,int ans)
{
    if(l>r)return ans;
    int mid=l+(r-l)/2;
    int count=0,t=0;
    bool x=false;
    for(int i=0;i<arr.size();i++)
    {
        t+=arr[i];
        if(t>=mid)
        {if(!x&&t==mid)x=true;if(t>=mid)count++,t=0;}
    }
    if(x&&count>=s)ans=max(ans,mid);
    if(l==r){return ans;}
    else if(count<s)return find(arr,l,mid-1,s,ans);//search for a smaller result
    else 
    return find(arr,mid+1,r,s,ans);//search for larger result
}
int main()
{
    vector<int> a;
    int sz,sum=0;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(!ss.eof())//input
    {
        string temp="";
        ss>>temp;
        int xy;
        if(stringstream(temp)>>xy)
            a.push_back(xy),sum+=xy;
    }
    cin>>sz;
    int l=1,r=sum;
    cout<<find(a,1,sum,sz+1,0);
    return 0;
}