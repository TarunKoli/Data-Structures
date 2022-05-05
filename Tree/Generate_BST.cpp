#include<iostream>
#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void Generate_BST(int arr[], int n){
	struct Stack stk;
	struct Node *p,*t;
	int i=0;
	
	root=(struct Node*)malloc(sizeof(struct Node));
	root->data=arr[i++];
	root->lchild=root->rchild=NULL;
	p=root;
	
	while(i<n){
		
		if(p->data>arr[i]){
				t=(struct Node*)malloc(sizeof(struct Node));
				t->data=arr[i++];
				t->lchild=t->rchild=NULL;
				p->lchild=t;
				push(&stk,p);
				p=t;
		}else{
			if(arr[i]>p->data && arr[i]<pop(&stk)->data)
			{
				t=(struct Node*)malloc(sizeof(struct Node));
				t->data=arr[i++];
				t->lchild=t->rchild=NULL;
				p->rchild=t;
				p=t;
			}else{
				p=pop(&stk);
			}
		}
			
	}
	
}
void inorder(struct Node *p){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}

int main(){
	int arr[8]={30,20,10,15,25,40,50,45};
	Generate_BST(arr,8);
	inorder(root);
	cout<<root->data;
	return 0;
}
