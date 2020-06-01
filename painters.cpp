#include<bits/stdc++.h>
using namespace std;
#define FO(i a b) for(int i=a;i<b;i++)
#define vE vector<int>
#define pb push_back;
#define sz(x) x.size()
void solve(vE in,int p)
{
	vector<vE> dp(p+1,vE(sz(in),0));
	dp[0][0]=in[0];
	FO(i 1 p+1)
		dp[i][0]=dp[0][0];
	FO(i 1 sz(in))
		dp[0][i]=dp[0][i-1]+in[i];
	FO(j 2 p+1)
		FO(i 1 sz(in))
		{
			dp[i][j]=max(max(dp[i-1][j-1],in[i]),dp[i][j-1]+in[i]);
		}


}
int main()
{
	vE in;
	int x;
	while(cin>> x)in.pb(x);
	int p= in[in.size()-1];
	in.pop_back();
	solve(in,p);	
	return 0;
}
/*
 * 15 2 21 1 13 3
 * 1 sum
 * if painters>=paintings ans=max(paintings)
 * dp
 *   25		2			21		1		13
 1   25		27			48 		49 		62 
 2   25        max(25,2)25          max(23,25,21)       max(48,1),22	              
 3   25 
 4   25
