#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int H[26]={0};
    int i;

    for(i=0;s[i]!=0;i++)
    {
        H[s[i]-97]++;
    }

    for(i=0;i<26;i++)
    {
        if(H[i]>1)
        cout<<(char)(i+97)<<" "<<H[i]<<endl;
    }

   return 0;
}   