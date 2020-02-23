#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s1;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                char x=board[i][j];
                if(x=='.')continue;
                string xx=to_string(x-'0');
                string r=to_string(i);
                string c=to_string(j);
                bool cbool=s1.insert("("+c+")"+xx).second;
                bool bbool=s1.insert("("+c+")"+xx+"("+r+")").second;
                bool abool=s1.insert(xx+"("+r+")").second;
                for(auto i:s1)
                    cout<<i<<endl;
                if(!abool||!bbool||!cbool)return false;
            }
        return true;
    }

int main()
{
	char x;
vector<vector<char>> v;
for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	{cin>>x;v.push_back(x);}	
cout<<isValidSudoku(v);
	return 0;
}
