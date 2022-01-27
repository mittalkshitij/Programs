#include<iostream>
using namespace std;

int getbit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}
int unique1(int a[],int n)
{
  int xorsum=0;
  for(int i=0;i<n;i++)
  {
      xorsum=xorsum^a[i];
  }
 return xorsum;
}

void unique2(int a[],int n)
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum^=a[i];
    }
    int tempxor=xorsum;
    int pos=0;
    int setbit=0;

    while(setbit!=1)
    {
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum >>1;
    }

    int newxor=0;
    for(int i=0;i<n;i++)
    {
        if(getbit(a[i],pos-1))
        {
          newxor=newxor^a[i];
        }
    }
    cout<<"The Unique elements are :"<<newxor<<" "<<(tempxor^newxor);
    
}
int main(){
  
int a[]={3,3,5,1,5,7,7};
int n=7;
cout<<"The Unique element is :"<<unique1(a,7)<<endl;

int arr[]={6,6,4,4,2,2,7,5};
int n1=8;
unique2(arr,n1);
return 0;
}