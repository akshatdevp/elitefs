#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int m=INT_MAX;
    int j=0;
    for(int i=k-1;i<n;i++)
    {
            m=min(m,v[i]-v[j++]);
    }
    cout<<m;
    return 0;
}
