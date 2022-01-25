#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int i,j;
    int n=s.length();

    for(i=0,j=n-1;i<j;i++,j--)
    {
        swap(s[i],s[j]);
    }

    cout<<s;


    return 0;
}