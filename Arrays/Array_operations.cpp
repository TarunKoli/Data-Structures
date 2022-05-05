#include<iostream>
using namespace std;

template <typename T>
class Array{
	private:
		T *arr;
		int size;
		int length;
		void extend_size();
	
	public:
		Array(int);
		void display();
		void push_back(T);
		void insert(T,int);
		void pop_back();
		void remove(int);
		int Search(T);
		int BinarySearch(T,int,int);
		int getLength();
		int getSize();
		T get(int);
		void set(int,T);
		T max();
		T min();
		void reverse();
		void leftShift();
		void rightShift();
		void leftRotate(int);
		void rightRotate(int);
		bool isSorted();
		T* Merge(T*,T*);
};

template <typename T>
void swap(T *a, T *b)
{
	T tmp=*a;
	*a=*b;
	*b=tmp;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

template <typename T>
int Array<T>::getLength(){
	return length;
}

template <typename T>
int Array<T>::getSize(){
	return size;
}

template <typename T>
void Array<T>::extend_size(){
	T *ptr=new T[size+10];
	
	for(int i=0; i<length; i++)
		ptr[i]=arr[i];
	
	size=size+10;
	arr=ptr;
	
}

template <typename T>
Array<T>::Array(int n){
	arr=new T[n];
	size=n;
	length=0;
}

template <typename T>
void Array<T>::display(){
	
	cout<<"Size : "<<size<<endl;
	cout<<"Length : "<<length<<endl;
	
	for(int i=0; i<length; i++)
		cout<<arr[i]<<" ";
		
	cout<<endl<<endl;
}

template <typename T>
void Array<T>::push_back(T n){
	
	if(size>length){
			arr[length]=n;
			length++;	
	}else{
		extend_size();
		push_back(n);
	}
			
}

template <typename T>
void Array<T>::insert(T val, int n){
	
	if(size>length){
		int i;
		for(i=length; i>n; i--){
			arr[i]=arr[i-1];	
		}
		arr[i]=val;
		length++;			
	}else{
		extend_size();
		insert(val,n);
	}
	
}

template <typename T>
void Array<T>::pop_back(){
	arr[length-1]=0;
	length--;
}

template <typename T>
void Array<T>::remove(int index){
	if(index>=0 && index<length)
	{
			for(int i=index; i<length-1; i++)
					arr[i]=arr[i+1];
			
			length--;
				
	}else{
		cout<<"Index not found"<<endl;
	}
}

template <typename T>
int Array<T>::Search(T n){
	for(int i=0; i<length; i++)
	{
		if(arr[i]==n)
			return 1;
	}
	return -1;
}

template <typename T>
int Array<T>::BinarySearch(T val,int l, int h){
	int i=l,j=h,mid;
	
	while(i<=j){
		mid=(i+j)/2;
		if(val==arr[mid])
			return 1;
		else if(val>arr[mid])
			i=mid+1;
		else
			j=mid-1;
	}
	
	return -1;
	
}

template <typename T>
T Array<T>::get(int index){
	if(index>=0 && index<=length)
		return arr[index];
}

template <typename T>
void Array<T>::set(int index, T val)
{
	if(index>=0 && index<getLength())
	{
			arr[index]=val;	
	}
}

template <typename T>
T Array<T>::max(){
	T maxi=arr[0];
	
	for(int i=0; i<getLength(); i++)
	{
			if(arr[i]>maxi)
				maxi=arr[i];
	}
	
	return maxi;
}

template <typename T>
T Array<T>::min(){
	int mini=arr[0];
	
	for(int i=0; i<getLength(); i++)
	{
			if(arr[i]<mini)
				mini=arr[i];
	}
	return mini;
}

template <typename T>
void Array<T>::reverse(){
	int i,j;
	
	for(i=0,j=getLength()-1; i<j; i++,j--)
	{
			swap(&arr[i],&arr[j]);
	}
	
}

template <typename T>
void Array<T>::leftShift(){
	int i=0;
	while(i<getLength()-1)
	{
		arr[i]=arr[i+1];
		i++;
	}
	length--;
}

template <typename T>
void Array<T>::rightShift()
{
		arr[getLength()-1]=0;
		length--;
}

template <typename T>
void Array<T>::leftRotate(int d){
		d=d%getLength();
		int g_c_d=gcd(d,getLength());
		
		for(int i=0; i<g_c_d; i++)
		{
				T temp=arr[i];
				int j=i;
				while(1){
					
					int k=j+d;
					
					if(k>=getLength())
						k=k-size;
					
					if(k==i)
						break;
				
					arr[j]=arr[k];
				
					j=k;
				}
				arr[j]=temp;
		}
		
}

template <typename T>
void Array<T>::rightRotate(int d){
	d=d%getLength();
	int g_c_d=gcd(d,getLength());
	
	for(int i=getLength()-1; i>(getLength()-g_c_d-1); i--)
	{
			T temp=arr[i];
			int j=i;
			
			while(1){
				int k=j-d;
				
				if(k<0)
					k=k+getLength();
				
				if(k==i)
					break;
				
				arr[j]=arr[k];
				j=k;	
			}
			arr[j]=temp;
			
	}
	
}

template <typename T>
bool Array<T>::isSorted(){
	
	for(int i=0; i<getLength()-1; i++)
	{
			if(arr[i]>arr[i+1])
				return false;
					
	}
	
	return true;

}

int main(){
	
	Array<int> A1(5);
	
	A1.push_back(1);
//	A1.display();
	A1.push_back(2);
//	A1.display();
	A1.push_back(3);
//	A1.display();
	A1.push_back(4);
//	A1.display();
	A1.push_back(5);
	A1.display();
//	A1.insert('f',0);
//	A1.pop_back();
//	A1.display();	
//	A1.remove(0);
//	A1.display();
//	(A1.BinarySearch('o',0,A1.getLength())==1) ? cout<<"Found":cout<<"Not Found"<<endl;
//	
//	cout<<A1.get(3)<<endl;
//	A1.set(3,'r');
//	cout<<A1.get(3)<<endl;	
//	cout<<"Maximum : "<<A1.max()<<endl;
//	cout<<"Minimum : "<<A1.min()<<endl;
	
//	A1.reverse();
//	A1.display();
//	A1.leftShift();
//	A1.display();
//	A1.rightShift();
//	A1.leftRotate(2);
//	A1.rightRotate(2);
//	A1.display();
//	(A1.isSorted()) ? cout<<"Sorted":cout<<"Not Sorted";
	return 0;
}
