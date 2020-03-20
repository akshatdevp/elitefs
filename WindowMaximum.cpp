#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,a;
vector<int> v;
cin>>x;
for(int i=0;i<x;i++)cin>>a,v.push_back(a);
cin>>a;
deque<int> dq;
for(int i=0;i<v.size();i++)
{
	for(int i=0;i<a;i++)
	{
		if(dq.empty())
			dq.push_front(i);
		else 

	}
}
	return 0;
}
