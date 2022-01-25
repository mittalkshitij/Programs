#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==1)
    {
        return 1;
    }

    return n*fact(n-1);
}
 
int nCr(int n,int r)
{

    int num=fact(n);
    int den=fact(r)*fact(n-r);

    return num/den;
}
int main()
{

    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);

   return 0;
}