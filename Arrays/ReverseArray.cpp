#include<bits/stdc++.h>
using namespace std;

int rev(int a[],int n)
{

    int i,j;

    for(i=0,j=n-1;i<j;i++,j--)
    {
        swap(a[i],a[j]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
   
}
int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    rev(a,n);

   return 0;
}