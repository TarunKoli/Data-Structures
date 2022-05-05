#include<iostream>
using namespace std;

void ArrayLeft(int A[],int size){
	int temp=A[0];
	int i;
	for(i=0; i<size; i++){
		A[i]=A[i+1];
	}
	A[--i]=temp;
}

void ArrayRotation(int A[],int d, int size){
	int repeats = d%size;
	for(int i=0; i<repeats; i++){
		ArrayLeft(A,size);
	}
}

void printArr(int A[], int size){
	for(int i=0; i<size; i++)
		cout<<A[i]<<" ";
}

void RotationArray(int A[],int d, int size){
		int temp[size];
		int repeats = d%size;
		for(int i=0; i<(size-repeats); i++){
			temp[i]=A[i+repeats];
		}
		for(int i=0; i<repeats; i++){
			temp[i+(size-repeats)]=A[i];
		}
		for(int i=0; i<size; i++){
			A[i]=temp[i];
		}
}

int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

void leftRotate(int A[], int d, int size){
	d=d%size;
	int g_c_d=gcd(d,size);
	
	for(int i=0; i<g_c_d; i++){
		int temp=A[i];
		int j=i;
		
		while(1){
			int k=j+d;
			
			if(k>=size){
				k=k-size;
			}
			
			if(k==i)
				break;
				
			A[j]=A[k];
			j=k;
			
		}
		
		A[j]=temp;
		
	}
	
}

int main(){
	int arr[5]={1,2,3,4,5};
	
	leftRotate(arr,2,5);
	printArr(arr,5);
	
	return 0;
}
