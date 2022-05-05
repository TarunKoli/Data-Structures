#include<iostream>
#include<stdlib.h>
using namespace std;

struct Array{
	int arr[20];
	int length;
};

struct Array Merge(struct Array *a,struct Array *b){
	struct Array A3;
	int i=0,j=0,k=0;
	
	while(i<a->length && j<b->length)
	{
		if(a->arr[i] < b->arr[j])
			A3.arr[k++]=a->arr[i++];
		else
			A3.arr[k++]=b->arr[j++];
	}
	
	for(;i<a->length;i++)
		A3.arr[k++]=a->arr[i];
	
	for(;j<b->length;j++)
		A3.arr[k++]=b->arr[j];
	
	A3.length=k;
	return A3;
}

struct Array Union(struct Array *a,struct Array *b){
	struct Array a3;
	
	int i=0,j=0,k=0;
	
	while(i<a->length && j<b->length){
			if(a->arr[i]<b->arr[j])
				a3.arr[k++]=a->arr[i++];
			else if(a->arr[i]==b->arr[j])
			{
					a3.arr[k++]=a->arr[i++];
					j++;
			}
			else
				a3.arr[k++]=b->arr[j++];
	}
	
	for(;i<a->length;i++)
		a3.arr[k++]=a->arr[i];
	
	for(;j<b->length;j++)
		a3.arr[k++]=b->arr[j];

	a3.length=k;
	return a3;
	
}

struct Array Intersection(struct Array *a,struct Array *b){
	struct Array a3;
	int i=0,j=0,k=0;
	
	while(i<a->length && j<b->length){
			if(a->arr[i]<b->arr[j])
				i++;
			else if(a->arr[i]==b->arr[j])
			{
				a3.arr[k++]=a->arr[i++];
				j++;
			}
			else
				j++;
	}
	
	a3.length=k;
	return a3;
	
}

struct Array Difference(struct Array *a,struct Array *b){
	struct Array a3;
	
	int i=0,j=0,k=0;
	
	while(i<a->length && j<b->length){
			if(a->arr[i]<b->arr[j])
				a3.arr[k++]=a->arr[i++];
			else if(a->arr[i]==b->arr[j])
			{
					i++;
					j++;
			}
			else
				a3.arr[k++]=b->arr[j++];
	}
	
	for(;i<a->length;i++)
		a3.arr[k++]=a->arr[i];
	
	for(;j<b->length;j++)
		a3.arr[k++]=b->arr[j];

	a3.length=k;
	return a3;

}

int main(){
	struct Array A1={{1,2,3,4,5},5};
	struct Array A2={{3,5,6,7,8},5};
	struct Array A3=Merge(&A1,&A2);
	struct Array A4=Union(&A1,&A2);
	struct Array A5=Intersection(&A1,&A2);
	Difference(&A1,&A2);
}
