#include<bits/stdc++.h>
using namespace std;
int x[10000];
int main()
{
	int w,n;
	cin>> w>> n;
	for(int i=0;i<n;i++)
		cin>> x[i];
	sort(x,x+n);
	int i=0,j=n-1;
	while(j>i)
	{
		if(x[i]+x[j]<=w)i++;
		j--;
	}
	cout<<n-i;
}
//1 2 10 20 
//1 2 3 4 5
//i       j
//  i    j
//  j i




