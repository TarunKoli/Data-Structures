#include<bits/stdc++.h>
using namespace std;

// Finding Duplicate in Sorted Array

void duplicate_sorted_1(int *a, int n)
{
		cout<<endl;
		
		// checks whether already printed element coming again to avoid multiple print
		int duplicate=0;
		
		// Loop through array
		for(int i=0; i<n; i++)
		{
				// as array is sorted therefore if the element is repeating they will subequently one after other.
				if(a[i]==a[i+1] && a[i]!=duplicate)
				{
						cout<<a[i]<<" ";
						duplicate=a[i];	
				}
		}
}


// Method 2
void duplicate_sorted_2(int *a, int n){
	cout<<endl;
	int i,j;
	
	for(i=0; i<n-1; i++)
	{
		if(a[i]==a[i+1]){
			j=i;
			
			// Skipping repeating elements
			while(a[j]==a[i])
				j++;				
	
			cout<<"Duplicate : "<<a[i]<<" Count : "<<j-i<<endl;
			i=j;
		}
	}
	
}

int main(){
	int arr[10]={3,6,8,8,10,12,15,15,15,20};
	duplicate_sorted_1(arr,10);
}
