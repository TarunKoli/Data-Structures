#include<iostream>
#include<string.h>
using namespace std;

// utility function

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

// Move all the negative elements to one side of the array 

// Two pointer approach

void NegvsPos(int arr[], int n){
	int i=0, j=n-1;
	int temp;
	
	while(i<j){
		if(arr[i]<0) i++;
		else if(arr[i]>0 && arr[j]<0){
			swap(arr[i],arr[j]);
		}
		
		if(arr[j]>0) j--;
	
	}
	
	i=0;
	while(i<n){
      cout<<arr[i]<<" ";
    	i++;
	}
}


// using auxillary space approach
void NegvsPos_2(int arr[], int n){
    
    int *res = new int[n];
    int i=0, k=0, j=n-1;
    
    while(i<n){
        if(arr[i]<0){
            res[k]=arr[i];
            k++;
        }else if(arr[i]>0){
            res[j]=arr[i];
						j--;
				}
				i++;
    }
    
    i=0;
    while(i<n){
      cout<<res[i]<<" ";
    	i++;
		}
}

int main(){
	int arr[5]={2,-1,1,-2,3};
	NegvsPos(arr,5);
	return 0;
}
