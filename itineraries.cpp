#include<bits/stdc++.h>
using namespace std;
bool DFS(map<string,set<pair<string,int> > > m,vector<bool>& vis,string src,int c,string ans,string &res)
{
    if(c==vis.size()){res=ans+" "+src;return true;}
    for(set<pair<string,int> >::iterator i=m[src].begin();i!=m[src].end();i++)
    {
        if(!vis[(*i).second])
            {   
                vis[(*i).second]=true;
                if(!DFS(m,vis,(*i).first,c+1,ans+" "+src,res)){}
                else return true;
                vis[(*i).second]=false;
            }    
    }
    return false;
}
int main()
{
    int x;
    cin>>x;
    string s1,s2;
    map<string,set<pair<string,int> > > m;
    for(int i=0;i<x;i++)
    {
        cin>>s1>>s2;
        m[s1].insert(make_pair(s2,i));
    }
    vector<bool> vis(x,false);
    //if(m.find("BZA")!=m.end()) //cout<<"BZA ";
    string res;
    DFS(m,vis,"BZA",0,"",res);
    cout<<res;
    return 0;
    
}
