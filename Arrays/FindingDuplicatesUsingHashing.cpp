#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int max=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int H[max]={0};
    
    for(int i=0;i<n;i++)
    {
        H[a[i]]++;
    }

    for(int i=0;i<max;i++)
    {
        if(H[i]>1)
        {
            cout<<H[i]<<" "<<i<<endl;
        }
    }
   return 0;
}   