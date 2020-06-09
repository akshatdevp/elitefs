#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,ans=0, c=1;
    cin>>x;
    while(x)
    {
        if(!(x&1))ans+=c;
        c=c<<1;
       x=x>>1;
    }
    cout<<ans;
    return 0;
}
/*
10
1010
   1
 4
5
101
 2
*/
