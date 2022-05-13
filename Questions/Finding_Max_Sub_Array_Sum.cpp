#include<bits/stdc++.h>
using namespace std;

// Utility function

long long find_max(int arr[],int n){
  long long maxi=arr[0];
	
	for(int i=0; i<n; i++) 
	if(maxi<arr[i]) maxi=arr[i];
		
		return maxi;
}

// AIM : find a subarray whose sum is maximum among all possible sub arrays (kaden's algo)

// Declare the two variables maxsum=0 (max sum), currsum=0 (current sum)

// Maxsum keeps the maximum sum till where the traversal of array is done

// Current sum holds the current sum which is upto latest element during traversal.

// if the current sum is getting bigger than maxsum assign the value of current sum to maximum sum.

// if the current sum is getting -ve discard that subarray , make currsum=0 and start from next element.


long long maxSubArraySum(int arr[], int n){
	long long maxsum=0;
	long long currsum=0;
	
	long long maximum=find_max(arr,n);

	
	// for handling all negative elements in array.
	if(maximum>=0){
		
		for(int i=0; i<n; i++){
			currsum=currsum+arr[i];
		
			if(currsum>maxsum){
				maxsum=currsum;
			}
		
			if(currsum<0){
				currsum=0;
			}
		
		}	

	}else{
		maxsum=maximum;
	}
	
	return maxsum;
}


int main(){
	int arr[5]={1,2,3,-2,5};
//	int arr1[4]={-1,-2,-3,-4};
	cout<<maxSubArraySum(arr,5);
}
