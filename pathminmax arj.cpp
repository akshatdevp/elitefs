#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>arr[i][j];//input
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if((i==0&&j==0)||(i==r-1&&j==c-1))
                arr[i][j]=INT_MAX;//not considering enter and exit positions
            else if(i==0)
                arr[i][j]=min(arr[i][j],arr[i][j-1]);//can only get value from left
            else if(j==0)
                arr[i][j]=min(arr[i][j],arr[i-1][j]);//can only get value from above
            else
                arr[i][j]=min(arr[i][j],max(arr[i-1][j],arr[i][j-1]));//minimum value considering maximum among above and left gives correct smallest value for optimal path
        }
    cout<<max(arr[r-2][c-1],arr[r-1][c-2]);
    return 0;
}

