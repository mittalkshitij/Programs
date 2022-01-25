#include<bits/stdc++.h>
using namespace std;
int main()
{
   
    int n;
    cin>>n;

    int a[n+1];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int x;
    cin>>x;

    int i=n-1;

    while(a[i]>x)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    n++;

    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
   return 0;
}