#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int a=0,b=0;
    int as[10]={0};
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i])
        b++;
	else{	as[s1[i]]++;
	if(as[s2[i]]>0)
		a++,as[s2[i]]--;
	}
    }
   cout<<b<<"A"<<a<<"B";

}
