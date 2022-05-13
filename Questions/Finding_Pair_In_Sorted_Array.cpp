#include<bits/stdc++.h>
using namespace std;

// Finding Pair in Sorted array

// Take two pointer One at start of array and other one at end of array.

// compute the sum of arr[i]+arr[j].

// If sum is less than given sum increment start pointer

// If sum is greater than given sum decrement end pointer


void finding_pair_sorted(int arr[], int n, int k){
	int i=0,j=n-1;
	
	while(i<j){
		
		if(arr[i]+arr[j]==k){
			cout<<arr[i]<<" + "<<arr[j]<<" = "<<k<<endl;
			i++;
			j--;
		}else if(arr[i]+arr[j]<k){
			i++;
		}else{
			j--;
		}
		
	}
	
}

int main(){
	int arr[11]={1,2,3,4,5,6,8,9,10,11,12};
	finding_pair_sorted(arr,10,10);
}
