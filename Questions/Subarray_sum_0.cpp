
#include <bits/stdc++.h>

using namespace std;


// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

// There are 3 cases which is possible for this problem.

// first if there is already a element 0

// second we keep on adding sum from starting and at some point it gets 0

// third if a element is repeating after a addition substraction of time. 

// foreg : [4 2 -3 1 6]  => 4+2=6
//                       => 6+(-3)=3
//                       => 3+1=4
// Therefore 4 is repeating that means elemnts between it gives 0 on addition
// => 2+(-3)+1=0;


bool subArrayExists(int arr[], int n)
{
        //Your code here
       
            int sum=0;
           unordered_map<int, int> um;
           
           for(int i=0;i<n; i++){
               sum=sum+arr[i];
               if(sum==0 || um[sum] || arr[i]==0){
                   return true;
               }else{
                   um[sum]=1;
               }
           }
            return false;    
        
}

int main()
{
    int arr[5] = {4, 2, -3, 1, 6};
    cout<<subArrayExists(arr,5);
    return 0;
}
