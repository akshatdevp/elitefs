#include<bits/stdc++.h>
using namespace std;
int main()
{

	int s1,s2,s3,sm1=0,sm2=0,sm3=0,p1=0,p2=0,p3=0;
	cin>>s1>>s2>>s3;
	int arr1[s1],arr2[s2],arr3[s3];
	for(int i=0;i<s1;i++)cin>>arr1[i],sm1+=arr1[i];
	for(int i=0;i<s2;i++)cin>>arr2[i],sm2+=arr2[i];
	for(int i=0;i<s3;i++)cin>>arr3[i],sm3+=arr3[i];
	while(p1<s1&&p2<s2&&p3<s3)
	{
		//cout<<sm1<<" "<<sm2<<" "<<sm3<<endl;
		if(sm1==sm2&&sm1==sm3){
		cout<<sm1;
		return 0;
		}
		int x=max(sm1,max(sm2,sm3));
		if(sm1==x)sm1-=arr1[p1++];
		if(sm2==x)sm2-=arr2[p2++];
		if(sm3==x)sm3-=arr3[p3++];
	}
	if(sm1==sm2==sm3)cout<<sm1;
	return 0;
}
/*
 * 3 2 1 1 1 sm=8
 * 4 3 2 sm=9
 * 1 1 4 1 sm=7
 * x=9
 * sm2=5 p2=1
 * x=8
 * sm1=5 p1=1
 *
 */
