#include<bits/stdc++.h>
using namespace std;


// Utility Functions

int max(int *a, int n){
	int maxi=a[0];
	for(int i=0; i<n; i++)
	{
			if(a[i]>maxi)
				maxi=a[i];
	}
	return maxi;
}

int min(int *a, int n){
	int mini=a[0];
	for(int i=0; i<n; i++)
	{
			if(a[i]<mini)
				mini=a[i];
	}
	return  mini;
}

// Finding Duplicate Elements in Unsorted array

void duplicate_unsorted(int *a, int n)
{
	// find out maximum element in array 
	int maxi=max(a,n);
	int mini=min(a,n);
	
	// Declare an array(hashmap) of size  maximum element
	int *b=new int[maxi];

	// Make the	hashmap element 0 initially
	for(int i=0; i<maxi; i++)
		b[i]=0;

	// Increment the index of element(value) by 1 each times it repeats
	for(int i=0; i<n; i++)
		b[a[i]]++;
	
	// Loop through the hashmap , Index having value more than 1 are repeating elements
	for(int i=0; i<maxi; i++)
		if(b[i]>1) 
			cout<<"Duplicate : "<<i<<" Count : "<<b[i]<<endl;
}


// Method 2 : Brute Force

void duplicate_unsorted(int *a, int n)
{
		int count =0;
		
		for(int i=0; i<n; i++)
		{
			count=1;
			if(a[i]!=-1){
				for(int j=i+1; j<n; j++)
				{
					if(a[i]==a[j]){
						count++;
						a[j]=-1;	
					}
				}
			}
			
			if(count>1){
				cout<<"Duplicate : "<<a[i]<<" Count : "<<count<<endl;
			}
			
		}
}


int main(){
	int arr[10]={3,5,6,4,10,7,1,5,5,7};
	duplicate_sorted_3(arr,10);
}
