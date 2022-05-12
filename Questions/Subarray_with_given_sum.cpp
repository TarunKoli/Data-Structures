#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{
        // Your code here
        
        // Declare a response array which will return the postions
        vector<int> res;
        
        // Declare three variable , namely two pointer which will act as 
				// sliding window and a variable which will hold the sum of this window
        long long curr_sum=arr[0], start=0, i;
 
 				//  Loop through the array       
        for(i=1; i<=n; i++){
            
            // If the window sum is greater the sum keeps on removing element from starting (windows sum)
						// and incrementing starting pointer 
            // until window sum becomes equal or less than given sum
						while(curr_sum>s && start<i-1){
                curr_sum = curr_sum-arr[start];
                start++;
            }
            
            // break or return if windows sum becomes equal to given sum
            if(curr_sum == s) {
                res.push_back(start+1);
		        res.push_back(i);
		        return res;
            }
            
            
            // If window sum is less than given sum keep on adding new element in windows sum
            if(i<n)
              curr_sum = curr_sum+arr[i];
            
        }
        
       
		res.push_back(-1);
        
        return res;
        
        
}

int main(){
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> a= subarraySum(A,10,15);
	cout<<a[0]<<" "<<a[1];
}
