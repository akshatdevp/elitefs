#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> &a,int n)
{
	for(int i=0;i<n-1;i++)
		if(a[i]>a[i+1])
			return false;
	return true;
}
int main()
{
	int n,l=-1,r=-1;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	if(isSorted(a,n))
		return 0;
	for(int i=0;i<n;i++)
	{
		if(i==0&&a[i]>a[i+1])
		{
			l=i; break;
		}
		else if(i!=n-1&&a[i]>a[i+1]&&a[i-1]< a[i])
		{
			l=i; break;
		}
	 }
	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1&&a[i]<a[i-1])
		{
			r=i; break;
		}
		else if(i!=0&&a[i]<a[i-1]&&a[i]<a[i+1])
		{
			r=i; break;	
		}
	}
	if(l!=-1||r!=-1)
	{
		swap(a[l],a[r]);
		if(isSorted(a,n))
		{
			cout<<"swap "<<l+1<<" "<<r+1<<endl;
		}
		else
		{
			swap(a[l],a[r]);
			reverse(a.begin()+l,a.begin()+r+1);
			if(isSorted(a,n))
			{
				cout<<"reverse "<<l+1<<" "<<r+1<<endl;
			}
			else
				cout<<"NOT POSSIBLE"<<endl;
		}
	}
	else
		cout<<"NOT POSSIBLE"<<endl;
	return 0;
}
