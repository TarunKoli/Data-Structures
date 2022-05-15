#include<iostream>
#include<string.h>
using namespace std;

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

 void sort012(int a[], int n)
  {
      // coode here 
        int *hashmap = new int[3];
    
        for(int i=0; i<3; i++)
            hashmap[i]=0;
    
        for(int i=0; i<n; i++)
            hashmap[a[i]]++;
        
        int j=0;
        for(int i=0; i<3; i++){
            while(hashmap[i]>0){
                a[j++]=i;
                hashmap[i]--;
            }
        }
        
        for(int i=0; i<n; i++)
        	cout<<a[i]<<" ";
}

int main(){
	int arr[5]={0, 2, 1, 2, 0};
	sort012(arr,5);
	return 0;
}
