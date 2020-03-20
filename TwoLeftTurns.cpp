//for zeroes, fill r->l sum
//for one left turn, take sum of above+1
//for two left turn, take sum of left+1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int arr[x][y],aux0[x][y],aux1[x][y],aux2[x][y];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++) 
        cin>>arr[i][j];
        for(int j=y-1;j>=0;j--)
        {
            aux0[i][j]=arr[i][j];
            if(j!=y-1)
            aux0[i][j]+=aux0[i][j+1];
        }
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i==0)aux1[i][j]=arr[i][j];
            else if(j==y-1)aux1[i][j]=0;
            else
            {
            aux1[i][j]=max(aux1[i-1][j],aux0[i-1][j])+arr[i][j];
            }
                
            }
    }
    int mx=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i==0||j==0)aux2[i][j]=aux1[i][j];
            else 
            {
                aux2[i][j]=aux2[i][j-1]+arr[i][j];
                mx=max(aux2[i][j],mx);
            }
        }
    }
    /*cout<<endl;
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
    cout<<aux0[i][j]<<" ";}cout<<endl;}
    cout<<endl;
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
    cout<<aux1[i][j]<<" ";}cout<<endl;}
    cout<<endl;
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
    cout<<aux2[i][j]<<" ";}cout<<endl;}*/
    cout<<mx;
    return 0;
}
/*

        1 2 3     6-0            5-0             3-0
        3 3 1     9-1/7-0         9+3/8-1/4-0        9+3+1/4-1/1-0    
        4 1 6     /max(9,7)+4=13-1/11-0       /max(8,4)+1=9-1/7-0                /max(4,1)+6=10/6-0
        
*/
