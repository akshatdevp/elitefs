#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int ans=0;
    vector<int> v(x);
    map<int,int> m;
    for(int i=0;i<x;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    if(y==1)
    {
        for(map<int,int> ::iterator it=m.begin();it!=m.end();it++)
        {
            int v=(*it).second;
            ans=ans+ max(((v*(v-1)*(v-2))/6),0);
        }
    }
    else{
    map<int,pair<int,int> > um;
    for(int i=1;i<x;i++)
    {
        if(um.find(v[i])==um.end())
            um[v[i]]=make_pair(0,0);
        if(m[v[i]/y])
            um[v[i]].first+=m[v[i]/y];
        if(um[v[i]/y].first)um[v[i]].second+=um[v[i]/y].first;
    }
    
    for(map<int,pair<int,int> >::iterator it=um.begin();it!=um.end();it++)
    {
        ans+=(*it).second.second;
    }
    }
    cout<<ans;
    return 0;
}
/*

 3 9 27 27 81 81
  
  m3-1
  9-1
  27-2
  81-2
  um 9-00
     3-1, 9-10
     27-00
     9-1 27-10 27-11
            21    22
  
   number of 2 sized tuples of v[i]= number of occurances of v[i]/y
   number of 3 sized tuples of v[i] = number of 2 sized tuples of v[i]/y

*/
