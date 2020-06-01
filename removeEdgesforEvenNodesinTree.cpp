#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > edges;
int dfs(int sou,vector<bool> vis,int num,vector<vector<int> > v)
{
    //cout<<sou<<" ";
    if(vis[sou])return 0;
    vis[sou]=true;
    for(int i=1;i<v[sou].size();i++)
    if(v[sou][i]&&!vis[i])num+=dfs(i,vis,1,v);
    return num;
}
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    vector<vector<int> > v(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
        edges.push_back(make_pair(a,b));
    }
    vector<bool> vis(n+1,false);
    int ans=0;
    for(int i=0;i<e;i++)
    {
        vis[edges[i].second]=true;
        int x=dfs(edges[i].first,vis,1,v);
        bool b1=x%2==0;
        vis[edges[i].second]=false;
        vis[edges[i].first]=true;
        int y=dfs(edges[i].second,vis,1,v);
        vis[edges[i].first]=false;
        //cout<<x<<" "<<y<<endl;
        bool b2=y%2==0;
        if(b1&&b2){ans++;v[edges[i].first][edges[i].second]=0,v[edges[i].second][edges[i].first]=0;}
    }
    cout<<ans;
    return 0;
}