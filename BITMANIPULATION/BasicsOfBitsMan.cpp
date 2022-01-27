#include<iostream>
using namespace std;

int getbit(int n,int pos)
{
    
  return ((n & (1<<pos))!=0);
}

int setbit(int n,int pos)
{
    return (n | (1<<pos));
}

int clearbit(int n,int pos)
{
    int cmp= ~(1<<pos);
    return (n & cmp);
}

int updatebit(int n,int pos,int val)
{
    int cmp=~(1<<pos);
    n=n & cmp;

    return (n | val<<pos);
}
int main(){
  
  cout<<getbit(5,2)<<endl;
  cout<<setbit(5,1)<<endl;
  cout<<clearbit(5,2)<<endl;
  cout<<updatebit(5,1,1)<<endl;

return 0;
}