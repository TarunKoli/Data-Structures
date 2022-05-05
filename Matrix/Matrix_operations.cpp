#include<iostream>
using namespace std;

class Diagonal_Matrix{
	private:
		int *arr;
		int dimension;
	
	public : 
		Diagonal_Matrix(int);
		int diagonal_matrix_get(int,int);
		void diagonal_matrix_set(int,int,int);
		void diagonal_matrix_display();
};

Diagonal_Matrix::Diagonal_Matrix(int d){
	dimension=d;
	arr=new int[d];
}

void Diagonal_Matrix::diagonal_matrix_set(int i,int j, int val){
	
	if(i==j && i<=dimension){
		arr[i-1]=val;
	}else{
		cout<<"Out of Diagonal bounds !"<<endl;
	}
	
}

int Diagonal_Matrix::diagonal_matrix_get(int i, int j){
	
	if(i==j){
		return arr[i-1];
	}else{
		cout<<"Diagonal element not found !"<<endl;
	}
	
}

void Diagonal_Matrix::diagonal_matrix_display(){
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			if(i==j)
				cout<<arr[i]<<" ";
			else
				cout<<0<<" ";
		}
		cout<<endl;
	}
}

class Lower_triangular_Matrix{
	protected:
		int *arr;
		int size;
		int dimension;
	
	public : 
	Lower_triangular_Matrix(int);
	void set(int, int, int);
	int get(int,int);
	void display();
};

Lower_triangular_Matrix::Lower_triangular_Matrix(int n){
	size=n;
	dimension=n*(n+1)/2;
	arr=new int[dimension];
	
	for(int i=0; i<dimension; i++)
		arr[i]=0;
	
}

void Lower_triangular_Matrix::set(int i,int j, int n){
	if(i>=j){
		arr[i*(i-1)/2+j-1]=n;
	}
}

int Lower_triangular_Matrix::get(int i, int j){
	if(i>=j){
		return arr[i*(i-1)/2+j-1];
	}else{
		return 0;
	}
}

void Lower_triangular_Matrix::display(){
for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(i>=j)
				cout<<arr[i*(i-1)/2+j-1]<<" ";
			else
				cout<<0<<" ";
		}
		cout<<endl;
	}
}

class Upper_triangular_Matrix{
	private :
		int *arr;
		int size;
		int dimension;

	public : 
		Upper_triangular_Matrix(int);
		void set(int, int, int);
		int get(int, int);
		void display();
};

Upper_triangular_Matrix::Upper_triangular_Matrix(int n){
	size=n;
	dimension=n*(n+1)/2;
	arr=new int[dimension];
	for(int i=0; i<dimension; i++)
	arr[i]=0;
}

void Upper_triangular_Matrix::set(int i, int j, int val){
	if(i<=j){
		arr[j*(j-1)/2+i-1]=val;
	}
}

int Upper_triangular_Matrix::get(int i, int j){
	if(i<=j){
		return arr[j*(j-1)/2+i-1];
	}else{
		return 0;
	}
}

void Upper_triangular_Matrix::display(){

	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(i<=j){
				cout<<arr[i]<<" ";
			}else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
	
}

class Symmetric_Matrix : public Lower_triangular_Matrix{
	public : 
		Symmetric_Matrix(int v):Lower_triangular_Matrix(v){}
		void Symmetric_Display();
};

void Symmetric_Matrix::Symmetric_Display(){
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			if(i>=j){
				cout<<arr[i*(i-1)/2+j-1]<<" ";
			}else{
					cout<<arr[j*(j-1)/2+i-1]<<" ";
			}
		}
		cout<<endl;
	}
}

class Tri_Diagonal_Matrix{
	private :
		int *arr;
		int size;
		int dimension;
	
	public : 
		Tri_Diagonal_Matrix(int);
		void set(int,int,int);
		int get(int,int);
		void display();
};

Tri_Diagonal_Matrix::Tri_Diagonal_Matrix(int n){
		size=n;
		dimension=3*n-2;
		arr=new int[dimension];
		
		for(int i=0; i<dimension; i++)
			arr[i]=0;
}

void Tri_Diagonal_Matrix::set(int i, int j, int val){
	if(i-j==1){
			arr[j-1]=val;
	}else if(i-j==-1){
			arr[2*size+j-3]=val;
	}else if(i==j){
			arr[size+j-2]=val;
	}
}

int Tri_Diagonal_Matrix::get(int i, int j){
	if(i-j==1){
			return arr[j-1];
	}else if(i-j==-1){
			return arr[2*size+j-3];
	}else if(i==j){
			return arr[size+j-2];
	}else{
		return 0;
	}
}

void Tri_Diagonal_Matrix::display(){
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			cout<<get(i,j)<<" ";
		}
		cout<<endl;
	}
}

class Toeplitz_Matrix{
	private : 
		int *arr;
		int size;
		int dimension;
			
	public : 
		Toeplitz_Matrix(int);
		void set(int,int,int);
		int get(int,int);
		void display();
};

Toeplitz_Matrix::Toeplitz_Matrix(int n){
	size=n;
	dimension=2*n-1;
	arr=new int[dimension];
	
	for(int i=0; i<dimension; i++)
		arr[i]=0;
}

void Toeplitz_Matrix::set(int i, int j, int val){
	if(i<=j && arr[j-i]==0){
		arr[j-i]=val;
	}else if(arr[size+i-j-1]==0){
		arr[size+i-j-1]=val;
	}
}

int Toeplitz_Matrix::get(int i, int j){
	if(i<=j){
		return arr[j-i];
	}else{
		return arr[size+i-j-1];
	}
}

void Toeplitz_Matrix::display(){
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			cout<<get(i,j)<<" ";
		}	
		cout<<endl;
	}
}

int main(){
	
//	Diagonal_Matrix m1(5);
//	
//	for(int i=1; i<=5;i++)
//		m1.diagonal_matrix_set(i,i,i+5);
//		
//	m1.diagonal_matrix_display();
	
//	Lower_triangular_Matrix m2(5);
//	
//	m2.set(1,1,1);
//	m2.set(2,1,2);
//	m2.set(2,2,3);
//	m2.set(3,1,4);
//	m2.set(3,2,5);
//	m2.set(3,3,6);
//	cout<<m2.get(1,2)<<endl;
//	m2.display();	
	
//	int n;
//	
//	Upper_triangular_Matrix m3(5);
//	for(int i=1; i<=5; i++){
//		for(int j=1; j<=5; j++){
//			cin>>n;
//			if(i<=j){
//				m3.set(i,j,n);
//			}
//		}
//	}
//	
//	cout<<endl;
//	m3.display();

//	int n;
//	Symmetric_Matrix m1(5);
//	
//	for(int i=1; i<=5; i++){
//		for(int j=1; j<=5; j++){
//			cin>>n;
//			if(i>=j){
//				m1.set(i,j,n);
//			}
//		}
//	}
//	cout<<endl;
//	m1.display();
//	cout<<endl;
//	m1.Symmetric_Display();

//	int n;
//	Tri_Diagonal_Matrix m1(5);
//	for(int i=1; i<=5; i++){
//		for(int j=1; j<=5; j++){
//			cin>>n;
//			m1.set(i,j,n);
//		}
//	}
//	m1.set(1,1,1);
//	m1.set(2,2,4);
//	m1.set(3,3,7);
//	cout<<endl;
//	m1.display();
	
	Toeplitz_Matrix m1(5);
	
	int n;
	for(int i=1; i<=5; i++){
		for(int j=1; j<=5; j++){
			cin>>n;
			m1.set(i,j,n);
		}
	}
	
	cout<<endl;
	m1.display();
	
	return 0;
}
