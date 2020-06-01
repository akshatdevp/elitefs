#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int x;
    while(cin>>x)arr.push_back(x);
    int adds[6];
    int subs[6];
    int mults[6];
    int divs[6];
    x=0;
    for(int i=0;i<3;i++)
        for(int j=i+1;j<4;j++)
        {
            adds[x]=arr[i]+arr[j];
            mults[x]=arr[i]*arr[j];
            divs[x]=max(arr[i],arr[j])/min(arr[i],arr[j]);
            subs[x]=arr[i]-arr[j];
            x++;
        }
    int res=1729;
    bool f=false;
    for(int i=0;i<3;i++)
    {
        x=mults[i];
        int y[]={adds[5-i],mults[5-i],subs[5-i],divs[5-i]};
            for(int a=0;a<4;a++)
	    {  //cout<<x<<" "<<y[a]<<endl;
		    if(x+y[a]==res||x*y[a]==res||x-y[a]==res||x/y[a]==res){f=true;}}
		    if(f)break;
        if(f)break;
    }
    cout<<f?"true":"false";
    return 0;
}
/*
01 10
02 20
03 30
12 
13
23
*/
