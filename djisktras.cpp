#include<bits/stdc++.h>
using namespace std;
int arr[9][9]=
{
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
};
int findmin(int src,vector<bool> vis,int n)
{
	int mind=-1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i]){
			if(mind==-1)mind=i;
			else mind=arr[src][mind]>arr[src][i]?i:mind;
		}
	}
	return mind;
}
void findshortestpath(int src,int n)
{
	vector<bool> vis(n,false);
	vis[src]=true;
	for(int i=0;i<n-1;i++){
		int v=findmin(src,vis,n);
		vis[v]=true;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&arr[v][j]&&arr[src][v])

			{	
				if(!arr[src][j])arr[src][j]=arr[v][j]+arr[src][v];
				else arr[src][j]=min(arr[src][j],arr[src][v]+arr[v][j]);
			}
		}

	}
}
int main()
{
	int n,src;
	//	cin>> n;
	//for(int i=0;i<n;i++)
	//for(int j=0;j<n;j++)
	//cin>> arr[i][j];
	n=9;
	//	cin>> src;
	src=0;
	findshortestpath(src,n);
	for(int i=0;i<n;i++)cout<<arr[src][i]<<" ";
	return 0;
}






























#include<bits/stdc++.h>
using namespace std;
int mini(vector<int> mins,vector<bool> vis)
{
	int mind,minimum=INT_MAX;
	for(int i=1;i<mins.size();i++)
		if(!vis[i]&&mins[i]<=minimum)
			minimum=mins[i],mind=i;
	return mind;
}
void dj(vector<vector<int> > arr,int src)
{
	vector<bool> vis(arr.size(),false);
	vector<int> mins(arr.size(),INT_MAX);
	mins[src]=0;
	for(int i=0;i<arr.size()-1;i++)
	{
		int x=mini(mins,vis);
		vis[x]=true;
		if(mins[x]==INT_MAX)continue;
		for(int j=0;j<arr.size();j++)
		{
			if(!vis[j]&&arr[x][j])
				mins[j]=min(mins[j],mins[x]+arr[x][j]);
		}
	}
	for(int i=0;i<arr[src].size();i++)
		if(src!=i)cout<<arr[src][i]<<" ";
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	vector<vector<int> >arr(n,vector<int> arr(n,0));
	for(int i=0;i<m;i++){cin>>a>>b;arr[a-1][b-1]=INT_MAX;arr[b-1][a-1]=INT_MAX;arr[i][i]=0;}
	cin>>a;
	dj(arr,a-1);
	return 0;
}
