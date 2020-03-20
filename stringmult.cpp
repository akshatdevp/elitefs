#include<bits/stdc++.h>
using namespace std;
string add(string s1,string s2,int shift)
{
	string ans="";
	while(shift>0)
		shift--,s2+="0";
	int i1=s1.size()-1,i2=s2.size()-1;
	//cout<<s1<<" "<<s2<<endl;
	int carry=0;
	while(i1>=0||i2>=0)
	{
		int a=0;
		if(i1>=0)a+=(s1[i1]-'0');
		if(i2>=0)a+=(s2[i2]-'0');
		a+=carry;
		ans=to_string(a%10)+ans;
		carry=a/10;
		//cout<<i1<<" "<<i2<<" "<<a<<" "<<carry<<" "<<ans<<endl;
		i1--;i2--;
	}
	if(carry==1)return to_string(carry)+ans;
	return ans;
	
}
int main()
{
	string s1,s2,ans="",finalans="0";
	int carry=0;
	cin>>s1>>s2;
	//cout<<s1<<s2<<endl;
	for(int i=s2.size()-1;i>=0;i--)
	{
		ans="";
		//cout<<ans<<endl;
		if((s2[i]-'0')==0)continue;
		for(int j=s1.size()-1;j>=0;j--)
		{
			if((s1[j]-'0')==0)break;
			int a=(s1[j]-'0')*(s2[i]-'0')+carry;
			carry=a/10;
			ans=to_string(a%10)+ans;
			//cout<<ans<<endl;
		}
		finalans=add(finalans,ans,s2.size()-1-i);	
	}
	cout<<finalans;
	return 0;
}
