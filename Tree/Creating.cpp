#include<iostream>
#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"
using namespace std;

struct Node *root=NULL;

void create_tree(){
	struct Node *p,*t;
	int val;
	struct Queue q;
	create(&q,100);
	
	cout<<"Enter the Root value : ";
	cin>>val;
	root=(struct Node*)malloc(sizeof(struct Node));
	root->data=val;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	
	while(!isEmpty(q)){
		p=dequeue(&q);
		
		cout<<"Enter left child of "<<p->data<<" : ";
		cin>>val;
		if(val!=-1){
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data=val;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		
		cout<<"Enter right child of "<<p->data<<" : ";
		cin>>val;
		if(val!=-1){
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data=val;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
	
}

void preorder(struct Node *p){
	if(p){
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct Node *p){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}

void postorder(struct Node *p){
	if(p){
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}

void IPreorder(struct Node *p){
	struct Stack stk;
	create_stack(&stk,100);
	
	while(!isStackEmpty(stk) || p){
		if(p){
			cout<<p->data<<" ";
			push(&stk,p);
			p=p->lchild;
		}else{
			p=pop(&stk);
			p=p->rchild;
		}
	}
	
}

void IInorder(struct Node *p){
	struct Stack stk;
	create_stack(&stk,100);
	
	while(!isStackEmpty(stk) || p){
		if(p){
			push(&stk,p);
			p=p->lchild;
		}else{
			p=pop(&stk);
			cout<<p->data<<" ";
			p=p->rchild;
		}
	}
	
}

struct Queue que;	
void LevelOrder(struct Node *p){
	if(p){
		
		if(p->lchild){
			cout<<p->lchild->data<<" ";
			enqueue(&que,p->lchild);
		}
			
		if(p->rchild){
			cout<<p->rchild->data<<" ";		
			enqueue(&que,p->rchild);
		}
			
		LevelOrder(dequeue(&que));
	}
}

void ILevelOrder(struct Node *p){
	
	cout<<p->data<<" ";
	enqueue(&que,p);
	
	while(!isEmpty(que)){
		p=dequeue(&que);
		
		if(p->lchild){
			cout<<p->lchild->data<<" ";
			enqueue(&que,p->lchild);
		}
		
		if(p->rchild){
			cout<<p->rchild->data<<" ";		
			enqueue(&que,p->rchild);
		}
		
	}
}

void IPostOrder(struct Node *p){
	struct Stack stk;
	create_stack(&stk,100);
	struct Node* temp;
	
	while(!isStackEmpty(stk) || p){
		if(p){
			push(&stk,p);
			p=p->lchild;
		}else{
			temp=pop(&stk);
			
			if(temp->data>0){
				temp->data=temp->data*-1;
				push(&stk,temp);
				p=temp->rchild;
			}else{
				int val=temp->data*-1;
				cout<<val<<" ";
				p=NULL;
			}
		}
	}
	
}

int count(struct Node *p){
	int x,y;
	if(p){
		x=count(p->lchild);
		y=count(p->rchild);
		return x+y+1;
	}
	return 0;
}

int sum(struct Node *p){
	int x,y;
	if(p){
		x=sum(p->lchild);
		y=sum(p->rchild);
		
		return x+y+p->data;
	}
	return 0;
}

int count_deg2_nodes(struct Node *p){
	int x,y;
	
	if(p){
		x=count_deg2_nodes(p->lchild);
		y=count_deg2_nodes(p->rchild);
		
		if(p->lchild && p->rchild){
			return x+y+1;
		}else{
			return x+y;
		}
	}
	return 0;
}

int count_deg1_nodes(struct Node *p){
	int x,y;
	if(p){
		x=count_deg1_nodes(p->lchild);
		y=count_deg1_nodes(p->rchild);
		
		if(
		  	(p->lchild && !p->rchild)  ||
		  	(!p->lchild && p->rchild)
		  ){
		  		return x+y+1;
			}else{
				return x+y;
			}
		
	}
	return 0;
}

int count_leaf_nodes(struct Node *p){
	int x,y;
	if(p){
		x=count_leaf_nodes(p->lchild);
		y=count_leaf_nodes(p->rchild);
		return x+y;
	}else{
		return 1;
	}
}

int fun(struct Node *p){
	int x,y;
	if(p){
		x=count_leaf_nodes(p->lchild);
		y=count_leaf_nodes(p->rchild);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
	return 0;
}


int main(){
	create_tree();
	cout<<endl;
//	preorder(root);
//	cout<<endl;
//	IPreorder(root);
//	cout<<endl;
//	inorder(root);
//	cout<<endl;
//	IInorder(root);
//	cout<<endl;
	postorder(root);
	cout<<endl;
	IPostOrder(root);
	
//	create(&que,100);
//	ILevelOrder(root);
//	cout<<endl;
	
//	cout<<root->data<<" ";
//	LevelOrder(root);
	
//	cout<<"Number of nodes : "<<count(root)<<" "<<endl;
//	cout<<"Sum of nodes : "<<sum(root)<<" "<<endl;
//	cout<<"Nodes with deg2 : "<<count_deg2_nodes(root)<<" "<<endl;
//	cout<<"Nodes with deg1 : "<<count_deg1_nodes(root)<<" "<<endl;
//	cout<<"Leaf Nodes : "<<count_leaf_nodes(root)<<" "<<endl;
//	cout<<fun(root);
	return 0;
}
