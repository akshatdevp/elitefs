#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	vector<string> s3,s4,ans;
	getline(cin,s1);
	getline(cin,s2);
	stringstream s1s(s1),s2s(s2);
	while(s1s>>s1)s3.push_back(s1);
	while(s2s>>s2)s4.push_back(s2);

	vector<int> count(26,0);
	for(int i=0;i<s4.size();i++)
	{
		vector<int> temp(26,0);
		for(int j=0;j<s4[i].size();j++)
		{
			temp[s4[i][j]-'a']++;
			count[s4[i][j]-'a']=max(count[s4[i][j]-'a'],temp[s4[i][j]-'a']);
		}
	}

	for(int i=0;i<s3.size();i++)
	{
		vector<int> temp(26,0);
		int x=0;
		for(int j=0;j<s3[i].size();j++)
			temp[s3[i][j]-'a']++;
		for(int j=0;j<26;j++)
			if(temp[j]<count[j]){x=1;break;}
		if(x==0)ans.push_back(s3[i]);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}
