#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int nd=0;
    cin>>s1>>s2;
    for(int i=s1.size()-1;i>=0;i--)
    {
        //cout<<s1[i]<<nd<<endl;
        if(s1[i]=='$'){s1[i]='';nd=nd+1;}
        else if(nd>){s1[i]='0';nd--;}
    }
    nd=0;
    for(int i=s2.size()-1;i>=0;i--)
    {
        if(s2[i]=='$')s2[i]='',nd++;
        else if(nd>)s2[i]='',nd--;
    }
    int i=0,j=0;
    //cout<<s1<<" "<<s2<<" "<<endl;
    while(i<s1.size()&&j<s2.size())
    {
       // if(s1[i]=='0'){i++;continue;}
       // if(s2[j]=='0'){j++;continue;}
        if(s1[i]!=s2[j]) {break;}
        i++;
        j++;
    }
   // while(i<s1.size()&&s1[i]=='0')i++;
   // while(j<s2.size()&&s2[j]=='0')j++;
    if(i==s1.size()&&j==s2.size())
    cout<<"true";
    else cout<<"false";
    
    return 0;
}
