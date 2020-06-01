
#include<bits/stdc++.h>
using namespace std;
int func(vector<vector<int>> arr,int stackno,int plates,int profit,int index,vector<vector<int> >dp)
{
	if(plates==0||stackno>=arr.size())return profit;
	//cout<<"HERE"<<profit<<" "<<stackno<<" "<<plates<<endl;
	if(index<arr[stackno].size())
	profit=max(dp[stackno][index]=max(dp[stackno][index],func(arr,stackno,plates-1,profit+arr[stackno][index],index+1)),dp[stackno+1][0]=max(dp[stackno+1][0],func(arr,stackno+1,plates,profit,0)));
	else 
		profit=func(arr,stackno+1,plates,profit,0);
	return profit;
}
int main()
{
int T,n,k,p;
	cin>>T;
	int a=1;
	while(a<=T)
	{
		cin>>n>>k>>p;
		vector<vector<int>>  arr(n, vector<int>(k,0));
		vector<vector<int>> dp(n+1,vector<int>(k+1,0));
		for(int i=0;i<n;i++)
			for(int j=0;j<k;j++)
				cin>>arr[i][j];
		//cout<<"HERE";
		int profit=func(arr,0,p,0,0);
		cout<<"Case #"<<a<<": "<<profit<<endl;
		a++;
	}
	return 0;
}
