// Finding Multiple Missing Elements in Sorted array

// Taking first element as the difference (a[i]-i).

// Loop through all element until element satisfy (a[i]-i=diff)

// If not print the element (diff+i) and increase the difference by 1
// repeat the same and find all missing element until next element in 
// array satisfy the changed difference.

#include<iostream>
using namespace std;

void find_multiple_sorted(int *a, int n){
	int diff=a[0];
	
	for(int i=0; i<n; i++){
		
		if(a[i]-i!=diff){
			
			while(diff!=a[i]-i){
				cout<<i+diff<<" ";
				diff++;
			}
			
		}
		
	}
	
}

int main(){
	int arr[10]={6,8,9,10,11,12,15,16,17,21};
	find_multiple_sorted(arr,10);
}
