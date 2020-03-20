#include<bits/stdc++.h>
using namespace std;
string ls[1000];
int y=0;
void func(string s1,string temp,vector<bool> vis)
{
	if(temp.size()==s1.size()){ls[y++]=temp;return;}
		for(int i=0;i<s1.size();i++)
		{
			if(vis[i]==false)
			{
				vis[i]=true;
				func(s1,temp+s1[i],vis);
				vis[i]=false;
			}
		}
}
int main()
{
	string s1;
	cin>>s1;
	vector<bool> vis(s1.size(),false);
	func(s1,"",vis);
	sort(ls,ls+y);
	for(int i=0;i<y;i++)
		cout<<ls[i]<<" ";
	return 0;
}
/*
 * ABC
 * A visa=true
 * AB visb=true
 * ABC visc=true
 *
 */
