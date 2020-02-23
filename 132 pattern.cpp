#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int x;
    while(cin>>x) v.push_back(x);
    vector<int> vs;
    vs.push_back(v[0]);
    int flag=0;
    for(int i=1;i<v.size();i++)
    {
        if(vs.size()==1)
        {
            if(v[i]<vs[0]) vs[0]=v[i];
            if(v[i]>vs[0]) vs.push_back(v[i]);
        }
        if(vs.size()==2)
        {
            if(v[i]>vs[1]) {if(v[i]<vs[0]) vs[0]=v[i]; else vs[1]=v[i];}
            if(v[i]<vs[1]) {if(v[i]>vs[0]){flag=1;cout<<"true"; break;}else vs[0]=v[i];}
        }
    }
    if(flag==0) cout<<"false"; 
    return 0;
}