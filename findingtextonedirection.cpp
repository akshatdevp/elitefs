#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<char> > v,int dx,int dy,string s1,int ind)
{
int directions[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
int indi=ind;
    for(int a=0;a<8;a++)
    {
        int x1=dx;
        int y1=dy;
        while(x1>=0&&x1<v.size()&&y1>=0&&y1<v[0].size()&&v[x1][y1]==s1[ind])
        {x1+=directions[a][0];y1+=directions[a][1];ind++;}
        if(ind==s1.size())return true;
        ind=indi;
    }
return false;
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<char>> v(r,vector<char>(c,'i'));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            cin>>v[i][j];
        }
    string s1;
    vector<pair<int,int> > vp;
    cin>>s1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(v[i][j]==s1[0])
            vp.push_back(make_pair(i,j));
        }
    for(int i=0;i<vp.size();i++)
    {
        int x=vp[i].first,y=vp[i].second;
                if(search(v,x,y,s1,0)){cout<<x<<" "<<y;return 0;}
    }
return 0;
    
}
    //cout<<"HERE";
