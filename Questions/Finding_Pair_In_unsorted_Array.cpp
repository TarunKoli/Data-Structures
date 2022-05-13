#include<bits/stdc++.h>
using namespace std;

// utility function

int max(int arr[], int n){
	int max=arr[0];
	
	for(int i=0; i<n; i++)
		if(arr[i]>max) max=arr[i];

	return max;
}

// Finding Pair in Unsorted array : Method 1 (Efficient)

// Declare a hashmap (say b[]), mark all the elements in hashmap

// Loop through the unsorted array

// check if the pair is present (b[sum-arr[i]]>0)

void finding_pair_unsorted_1(int arr[], int n, int k){
	int maxi=max(arr,n);
	
	int *b=new int[maxi+1];
	
	for(int i=0; i<maxi+1; i++)
		b[i]=0;
	
	for(int i=0; i<n; i++)
		b[arr[i]]++;
		
	for(int i=0; i<n; i++){
		if(b[k-arr[i]]>0){
			cout<<arr[i]<<" + "<<k-arr[i]<<" = "<<k<<endl;
			b[arr[i]]=b[k-arr[i]]=0;
		}
	}
		
}


// Method 2 : brute force

void finding_pair_unsorted_2(int arr[], int n, int k){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(arr[i]+arr[j]==k){
				cout<<arr[i]<<" + "<<arr[j]<<" = "<<k<<endl;
			}
		}
	}
}


int main(){
	int arr[10]={3,5,6,4,10,7,1,9,2,8};
	finding_pair_unsorted_1(arr,10,10);
}
