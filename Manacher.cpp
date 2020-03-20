#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2="";
	cin>>s1;
	for(int i=0;i<s1.size();i++)
	{
		s2+="$";
		s2+=s1[i];
	}
	s2+="$";
	//cout<<s2;
	int pals[s2.size()]={0};
	for(int i=1;i<s2.size()-1;i++)
	{
		int L=i-1;
		int R=i+1;
		while(L>-1&&R<s2.size()&&s2[L--]==s2[R++])pals[i]++;
		cout<<pals[i];
	}

	return 0;
}
