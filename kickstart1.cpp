#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,B;
	cin>>T;
	int a=1;
	while(a<=T)
	{
		cin>>N>>B;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		//cout<<"HERE1"<<endl;
		long dp[N+1][B+1];
		for(int i=0;i<N+1;i++)
			for(int j=0;j<B+1;j++)
			{
				//cout<<"HERE";
				if(j==0||i==0)dp[i][j]=0;
				else
					dp[i][j]=(j>=arr[i-1]?max(1+dp[i-1][j-arr[i-1]],dp[i-1][j]):dp[i-1][j]);
			}
		//cout<<"HERE"<<" ";
		cout<<"Case #"<<a<<": "<<dp[N][B]<<endl;
		a++;
	}

	return 0;
}
