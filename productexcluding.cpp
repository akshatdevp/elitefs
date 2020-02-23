#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr1[100],arr2[100],x=0,r=1;
	int j;
	cin>>j;
	while(x<j)
	cin>>arr1[x++];
	arr2[0]=1;
	for(int i=1;i<x;i++) arr2[i]=arr1[i-1]*arr2[i-1];
	for(int i=x-1;i>=0;i--)
	{
		arr2[i]*=r;
		r*=arr1[i];
	}
	for(int i=0;i<x;i++)
		cout<<arr2[i]<<" ";
}
// 2 3 4 5
// 1 2 6 24
// 24 r=5
// 30 r=20
// 40 r=60
// 60 r=120
//
