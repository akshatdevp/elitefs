#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	string s1;
	getline(cin,s1);
	stringstream(s1)>>n;
	vector<vector<int> > arr;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		getline(cin,s1);
		stringstream s2(s1);
		while(s2>>x)temp.push_back(x);
		arr.push_back(temp);
	}
	map<int,int> um;
	for(int i=0;i<n;i++)
		for(int j=0,x=0;j<arr[i].size()-1;j++)
		{
			x+=arr[i][j];
			um[x]++;
		}
	int ma=INT_MAX;
	for(map<int,int>::iterator it=um.begin();it!=um.end();it++)
	{
		//cout<<(*it).first<<" "<<(*it).second<<endl;
		ma=min(ma,n-(*it).second);
	}
	cout<<ma;
	return 0;
}
