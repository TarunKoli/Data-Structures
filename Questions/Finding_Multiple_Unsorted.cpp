// Finding Multiple Missing Elements in Un-sorted array

// Find out the maximum and minimum element in the array

// Create a dynamic array of size Maximum (Hash map)

// loop through the unsorted array and increment index by 1 in Hashmap(value of array element)

// loop through hashmap from minium element to Maximum element

// element between maximum and minimum which have index value 0 are missing elements

#include<iostream>
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

void find_multiple_unsorted(int *a, int n){
	cout<<endl;
	int maxi=max(a,n);
	int mini=min(a,n);
	
	int *b=new int[maxi+1];
	
	for(int i=0; i<n; i++)
		b[i]=0;
	
	for(int i=0; i<n; i++)	
		b[a[i]]++;
	
	for(int i=mini; i<=maxi;i++)
	{
		if(b[i]==0)
			cout<<i<<" ";
	}
	
}

int main(){
int arr[8]={3,6,4,10,7,1,2,8};
	find_multiple_unsorted(arr,8);
}
