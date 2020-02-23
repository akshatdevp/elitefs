#include<bits/stdc++.h>
using namespace std;
    void boundary(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis,int arr[4][2])
    {
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1||vis[i][j]||grid[i][j]==0)
            return;
        vis[i][j]=true;
	for(int a=0;a<4;a++)
             boundary(grid,i+arr[a][0],j+arr[a][1],vis,arr);
    }
    int numIslands(vector<vector<int>>& grid,vector<pair<int,int>> &v ) {
     
        if(grid.size()==0)
            return {};
        int n=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
          int arr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	  for(auto i:v)
          {
              if(vis[i.first][i.second]) continue;
              n++;
              boundary(grid,i.first,i.second,vis,arr);
          }
        return n;
    }
int main()
{
int x,y,z,t1,t2;
cin>>x>>y>>z;
vector<vector<int>> v(x,vector<int>(y,0));
vector<pair<int,int>> g;
for(int i=0;i<z;i++)
{
cin>>t1>>t2;
g.push_back(pair<int,int>(t1,t2));
v[t1][t2]=1;
cout<<numIslands(v,g);
}
return 0;
}

