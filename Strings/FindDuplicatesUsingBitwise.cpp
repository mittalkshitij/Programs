#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    long int H=0,x=0;
    int i,n=s.length();

    for(int i=0;i<n;i++)
    {
        x=1;
        x=x<<(s[i]-97);

        if((x&H)>0)
        {
            cout<<s[i];
        }
        else
        H=x|H;
    }
   return 0;
}