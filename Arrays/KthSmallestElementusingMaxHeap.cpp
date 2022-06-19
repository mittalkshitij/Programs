#include<bits/stdc++.h>
using namespace std;

void ksmallele(vector<int> v1,int k)
{
    priority_queue<int,vector<int>> pq(v1.begin(),v1.begin()+k);

    for(int i=k;i<v1.size();i++)
    {
        if(v1[i]<pq.top())
        {
            pq.pop();
            pq.push(v1[i]);           
        }
    }
                                            // TIME COMPLEXITY - 0(n.logk)
    cout<<pq.top();
}

int main()
{
   
   vector<int> v;

   int x;
   for(int i=0;i<6;i++)
   {
    cin>>x;
    v.push_back(x);
   }
    int k;
    cin>>k;
   ksmallele(v,k);
   return 0;
}