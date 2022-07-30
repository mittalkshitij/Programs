

// next_permutation 
next_permutation in STL is a built-in function which as the name suggests 
returns the next lexicographically greater permutation of the elements in the container passed to it as an argument.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

// OUTPUT- 2 1 3





















// __builtin_popcount()


The function takes an unsigned integer as input parameter and returns the number of set bits present in that integer.
Note: This function only works for unsigned or positive integers.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int n = 7;
    
    cout<<__builtin_popcount(n);
    
    return 0;
}


if the integer is of the type “long long” and not fits in the range of int?

In that case, there is a separate function with slight variation in function name but serves exactly the same purpose.
 The function is __builtin_popcountll(). Notice the ll in the end of function name.

 #include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    long long n = 77777777777777;
    
    cout<<__builtin_popcountll(n);
    
    return 0;
}

























// sort()


   
    int arr[] = {4,2,1};

    sort(arr, arr+3);


       vector<int> vec = {4,2,1};

    sort(vec.begin(), vec.end());












    //min_element() 

     vector<int>v {4,2,5,9,1};
    cout<<"The elements in the vector are: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    cout<<"The minimum element is: "<<*min_element(v.begin(),v.end());



    // max_element()'

vector<int>v {4,2,5,9,1};
    cout<<"The elements in the vector are: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    cout<<"The maximum element is: "<<*max_element(v.begin(),v.end());