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
    int flag=1;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }

    if(flag==0){
        cout<<"Array is not sorted";
    }
    else{
    cout<<"Array is sorted";
    }
   return 0;
}