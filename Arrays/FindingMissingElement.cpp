#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;

    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int l=a[0];
    int h=a[n-1];

    int diff=l-0;

    for(i=0;i<n;i++)
    {
        
        if(a[i]-i!=diff)
        {
            while(diff<a[i]-i)
            {
            cout<<diff+i<<" ";
            diff++;
            }
        }
    }

   return 0;
}

///a[i]-- 1 2 3 4 5 6 7 10 11 12
///  i -- 0 1 2 3 4 5 6 7  8  9