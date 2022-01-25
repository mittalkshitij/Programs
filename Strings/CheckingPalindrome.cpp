#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int i,j;
    int n=s.length();
    int flag=1;

    for(i=0,j=n-1;i<j;i++,j--)
    {
        if(s[i]==s[j])
        flag=1;
        else
        {
            flag=0;
            break;
        }
    }

    cout<<flag;


   return 0;
}