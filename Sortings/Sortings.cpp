#include<bits/stdc++.h>
using namespace std;

// Utility Functions

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[], int l, int h){
	int i,j,pivot;
	
	pivot=arr[l];
	i=l;
	j=h;
	
	do{

		do{ i++; }while(arr[i]<=pivot);
		do{ j--; }while(arr[j]>pivot);
		
		if(i<j) swap(&arr[i],&arr[j]);
	}while(i<j);
	
	swap(arr[l],arr[j]);
	return j;
	
}

void Merge(int A[],int l, int mid, int h){
	int i=l,j=mid+1,k=l;
	int B[100];
	
	while(i<=j && j<=h)
	{
		
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
			
	}
	
	for(; i<=mid; i++)
		B[k++]=A[i];
	
	for(; j<=h; j++)
		B[k++]=A[j];
	
	for(i=l; i<=h; i++){
		A[i]=B[i];
	}
}

int findMax(int A[], int n){
	int  max=-1;
	
	for(int i=0; i<n; i++)
	{
			if(A[i]>max)
				max=A[i];
	}
	
	return max;
	
}


// Sorts

void BubbleSort(int arr[],int n)
{
	int flag=0;
	
	for(int i=0; i<n-1; i++){
		
		flag=0;
		
		for(int j=0;j<n-i-1; j++){
			
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				flag=1;
			}
			
		}
		
		if(flag==0){
			break;
		}
	
	}
}

void InsertionSort(int arr[],int n){
	int x,j;
	
	for(int i=1; i<n; i++){
		
		j=i-1;
		x=arr[i];
		
		while(j>-1 && arr[j]>x){
			arr[j+1]=arr[j];
			j--;
		}
		
		arr[j+1]=x;
		
	}
		
}

void MergeSort(int A[], int n){
	int i,p,l,h,mid;
	
	for(p=2; p<=n; p=p*2){
		
		for(i=0; i+p-1<n; i=i+p){
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			Merge(A,l,mid,h);
		}
		
	}
	
	if(p/2<n){
		Merge(A,0,p/2-1,n-1);
	}

}

void SelectionSort(int arr[], int n){
	int x,y;
	
	for(int i=0; i<n-1; i++){
		
		for(y=x=i; y<n; y++){
			
			if(arr[x]>arr[y]){
				x=y;	
			}
		
		}
	
		swap(&arr[x],&arr[i]);
	
	}
	
}

void QuickSort(int arr[], int l, int h){
	int j;
	if(l<h){
		j=partition(arr,l,h);
		QuickSort(arr,l,j);
		QuickSort(arr,j+1,h);
	}
}

void CountSort(int A[], int n){
	int i,j,max,*C;
	
	max=findMax(A,n);
	
	C=new int[max+1];
	
	for(i=0; i<max+1; i++)
		C[i]=0;
	
	for(i=0; i<n; i++){
		C[A[i]]++;
	}
	
	i=0; j=0;
	
	while(j<max+1){
		
		if(C[j]>0){
			A[i++]=j;
			C[j]--;
		}else{
			j++;
		}

	}

}


int main(){
	int arr[15]={8,5,3,6,9,2,1,4,7,3,7,9,2,5,18};
		//CountSort(arr,15);

	MergeSort(arr,14);
	// BubbleSort(arr,10);
	// InsertionSort(arr,10);
	// SelectionSort(arr,10);
	//QuickSort(arr,0,10);
	
	for(int i=0; i<15; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
