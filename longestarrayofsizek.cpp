#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	vector<int> v;
	vector<pair<int,int> > pre;
	while(cin>>x)v.push_back(x);
	pre.push_back(make_pair(v[0],1));
	for(int i=1;i<v.size();i++)
	{
		if(pre[pre.size()-1].first==v[i]) pre[pre.size()-1].second++;
		else pre.push_back(make_pair(v[i],1));
	}
	int ans=pre[0].second+pre[1].second,tempans=ans;
	//for(int i=0;i<pre.size();i++)cout<<pre[i].first<<" "<<pre[i].second<<endl;
	for(int i=2;i<pre.size();i++)
	{
		tempans+=pre[i].second;
		if(pre[i].first!=pre[i-1].first&&pre[i].first!=pre[i-2].first)tempans-=pre[i-2].second;
		ans=max(tempans,ans);
	}
	cout<<ans;
	return 0;
}


//lsfdfdfosafsdngestarrayofsizek.cpp
//3 3 3 1 2 1 1 2
//     
