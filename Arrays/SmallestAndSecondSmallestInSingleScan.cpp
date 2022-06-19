#include<bits/stdc++.h>
using namespace std;

void print2smallest(int arr[])
{
  int smallest, sec_smallest;

  smallest=sec_smallest=INT_MAX;

  for(int i=0;i<6;i++)
  {
    if(arr[i]<smallest)
    {
        sec_smallest=smallest;
        smallest=arr[i];
    }

    else if(arr[i]<sec_smallest && arr[i]!=smallest)
    {
        sec_smallest=arr[i];
    }
  }
                                                          //Time Complexity: O(n)

                                                          //Auxiliary Space: O(1)
  cout<<"Smallest : "<<smallest<<endl;
  cout<<"Second Smallest : "<<sec_smallest;

}

int main()
{
    int a[6];

    for(int i=0;i<6;i++)
    {
        cin>>a[i];
    }

    print2smallest(a);

   return 0;
}