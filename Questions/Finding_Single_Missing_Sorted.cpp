#include<iostream>
using namespace std;


// Finding single missing element in a sequence of Sorted array

// Find the sum of sequence till last element (n=12)

// Using sum=n(n+1)/2;

// Find the sum of elements in the array.

// Find Missing Element (missing= sum(seq)-sum(arr));

// [Note : Only for sorted array
//				 Only finds single element.
//				 Only possible if the element are in sequence i.e 1 to n ]


// Code : 

int find_single_natural_sorted(int *a, int n){
	int s=0,sum=0;
	sum=a[n-1]*(a[n-1]+1)/2;
	
	for(int i=0; i<n; i++)
	{
			s=s+a[i];
	}
	
	int diff=sum-s;
	
	return diff;
}


// Initialized the first element as the difference a[0] (because a[0]-0=a[0]) 
// In this case (difference = a[i]-i) which should be equal for all elements
// Where i is the index of elements

// example arr[1,2,4,5];
//		for(i=0) a[0]-0=1;
// 		for(i=1) a[1]-1 = 2-1 = 1; and so on.....
// 	If any index does give the same difference with its elements then missing is (a[i]-diff)
//		for(i=2) a[2]-2 = 4-2 = 2 (which is not equal to diff=1)
// 		Therefore, missing=a[2]-diff = 4-1 = 3
			
void find_single_natural_sorted_2(int *a,int n){
	int diff=a[0];
	
	for(int i=0; i<n; i++)
	{
			if(a[i]-i!=diff){
				cout<<a[i]-diff<<" "<<endl;
				break;
			}
	}
	
}

int main(){
	int arr[11]={1,2,3,4,5,6,8,9,10,11,12};
	int res=find_single_natural_sorted(arr,11);
	res?cout<<res<<" missing"<<endl:cout<<"No Element Missing"<<endl;
}
