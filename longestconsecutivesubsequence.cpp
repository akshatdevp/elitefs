#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
	unordered_set<int> us;
	for(int i=0;i<nums.size();i++)us.insert(nums[i]);
	int streak=1, mx=1;
	for(int i:us)
	{
		if(us.find(i-1)!=us.end())continue;
		while(us.find(i+1)!=us.end())
			i++,streak++;
		mx=max(mx,streak);
		streak=1;
	}
	return mx;
    }
int main()
{
	vector<int> v;
	int x;
	while(cin>>x)v.push_back(x);
	cout<<longestConsecutive(v);
	return 0;
}
// 100 4 200 1 3 2
// 100 go left nothing, go right nothing,
// 4 go left nothing, go right find 3 count++
// 3 go left nothing, go right find 2 count++
// 2 go left nothing, go right find 1 count++
// 1 nothing nothing count=0
// 200 nothing.
//
