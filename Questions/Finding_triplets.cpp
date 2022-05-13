#include<bits/stdc++.h>
using namespace std;


// Finding Triplets in an array whose sum is equal to given sum

// Sort the array if unsorted

// From triplet we fix one element using outer loop

// In Inner loop we use two pointer to find out the sum (finding pair in sorted array procedure)

// A start Pointer at start of array and a end pointer at end of array

// A[i](fixed in inner loop) + A[start] + A[end]

// if sum is greater than we decrement ending pointer

// if sum is leff than we increment starting pointer

// if no element is found , fixed element is changed by outer loop everytime.

bool find3Numbers(int A[], int n, int X)
{
    int l,r;
    sort(A, A + n);

    for(int i=0; i<n; i++){
        l=i+1;
        r=n-1;
        
        while(l<r){
            if(A[i]+A[l]+A[r]==X){
                return true;
            }else if(A[i]+A[l]+A[r]<X){
                l++;
            }else{
                r--;
            }
        }
    }
    
    return false;
}


int main(){
	int arr[6]={1, 4, 45, 6, 10, 8};
	cout<<find3Numbers(arr,6,13);
}
