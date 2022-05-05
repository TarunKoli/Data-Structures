#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	
	// method 1
	int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	
	
	// method 2
	int *B[3]; // rows number in stack
	B[0]=(int *)malloc(3*sizeof(int)); // Size having 3 columns
	B[1]=(int *)malloc(3*sizeof(int));
	B[2]=(int *)malloc(3*sizeof(int));
	
	// for(int i=0; i<3; i++){
	//	for(int j=0; j<3; j++){
	//		B[i][j]=A[i][j];
	//	}
	// }
	
	
	// method 3 (preffered)
	int **C;
	
	C=(int **)malloc(3*sizeof(int*)); // rows number in heap (dynamic)
	C[0]=(int *)malloc(3*sizeof(int)); // Size having 3 columns
	C[1]=(int *)malloc(3*sizeof(int));
	C[2]=(int *)malloc(3*sizeof(int));
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			C[i][j]=A[i][j];
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
