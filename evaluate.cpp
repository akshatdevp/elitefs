#include<bits/stdc++.h>
using namespace std;
int pre(char op)
{
	if(op=='*'||op=='/') return 2;
	if(op=='+'||op=='-') return 1;
	return 0;
}

int app(int v1,int v2,char op)
{
	if(op=='+') return v1+v2;
	if(op=='*') return v1*v2;
	if(op=='/') return v1/v2;
	if(op=='-') return v1-v2;
}
int eval(string s)
{
	stack<int> nums;
	stack<char> op;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ')
			continue;
		 if(s[i]=='(')
			op.push('(');
		 if(isdigit(s[i]))
				{
					int v=0;
					while(i<s.length()&&isdigit(s[i]))
						{
							v*=10;
							v+=s[i++]-'0';
							
						}
					nums.push(v);
				}
		 if(s[i]==')')
			{
				while(!op.empty()&&op.top()!='(')
					{
						int v1=nums.top();nums.pop();
						int v2=nums.top();nums.pop();
						char o=op.top();op.pop();
						nums.push(app(v1,v2,o));
					}
				if(!op.empty())
				op.pop();
			}
		
			
				while(!op.empty()&&pre(op.top())>=pre(s[i]))
					{
						
						int v1=nums.top();nums.pop();
						int v2=nums.top();nums.pop();
						char o=op.top();op.pop();
						nums.push(app(v1,v2,o));
					}
					op.push(s[i]);
			
		}
		while(!op.empty())
			{
				
				int v1=nums.top();nums.pop();
				int v2=nums.top();nums.pop();
				char o=op.top();op.pop();
				nums.push(app(v1,v2,o));
			}
		return nums.top();

}
int main()
{
	string s;
	getline(cin,s);
	cout<<eval(s);
	return 0;
}
