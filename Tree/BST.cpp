#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

void Insert(int key){
	struct Node *t=root;
	struct Node *r=NULL,*p;
	
	if(root==NULL){
		p=(struct Node *)malloc(sizeof(struct Node));
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	
	while(t!=NULL){
		r=t;
		
		if(key<t->data){
			t=t->lchild;
		}else if(key>t->data){
			t=t->rchild;
		}else{
			return;
		}	
	
	}
	
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=key;
	p->lchild=p->rchild=NULL;

	if(key<r->data){
		r->lchild=p;
	}else{
		r->rchild=p;
	}	

}

void Recursive_Insert(struct Node *p, int key){
	static struct Node *r;
	struct Node *t;
	
	if(root==NULL){
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		root=t;
		return;
	}
	
	if(p){
		r=p;
		if(key==p->data){
			return;
		}else if(key<p->data){
			Recursive_Insert(p->lchild,key);
		}else{
			Recursive_Insert(p->rchild,key);
		}	
	}else{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		
		if(key<r->data){
			r->lchild=t;
		}else{
			r->rchild=t;
		}
		
	}
	
}

int Height(struct Node *p){
	int x,y;
	if(p){
		x=Height(p->lchild);
		y=Height(p->rchild);
		
		return x>y ? x+1:y+1;
	}
	return 0;
}

struct Node* InPre(struct Node *p){
	
	while(p && p->rchild!=NULL){
		p=p->rchild;
	}
	
	return p;
}

struct Node* InSucc(struct Node *p){
	
	while(p && p->lchild!=NULL){
		p=p->lchild;
	}
	
	return p;
}

struct Node* Delete(struct Node *p, int key){
	
	struct Node *q;
	
	if(p==NULL)
		return NULL;
	
	if(p->lchild==NULL && p->rchild==NULL){
		if(p==root)
			root=NULL;
		free(p);
		return NULL;
	}
	
	if(key<p->data)
		p->lchild=Delete(p->lchild,key);
	else if(key>p->data)
		p->rchild=Delete(p->rchild,key);
	else{
		
		if(Height(p->lchild)>Height(p->rchild)){
			q=InPre(p->lchild);
			p->data=q->data;
			p->lchild=Delete(p->lchild,q->data);
		}else{
			q=InSucc(p->rchild);
			p->data=q->data;
			p->rchild=Delete(p->rchild,q->data);	
		}
		
	}
	return p;
}

struct Node* Search(struct Node *p, int key){
	if(p){
		if(p->data==key){
			return p;
		}else if(key<p->data){
			return Search(p->lchild,key);
		}else{
			return Search(p->rchild,key);
		}
	}
}

struct Node* ISearch(struct Node *p, int key){
	
	while(p!=NULL){
		
		if(p->data==key){
			return p;
		}else if(key<p->data){
			p=p->lchild;
		}else{
			p=p->rchild;
		}
	
	}
	return NULL;
}

void Inorder(struct Node *p){
	if(p){
		Inorder(p->lchild);
		cout<<p->data<<" ";
		Inorder(p->rchild);
	}
}

int main(){
	Recursive_Insert(root,10);
	Recursive_Insert(root,5);
	Recursive_Insert(root,20);
	Recursive_Insert(root,8);
	Recursive_Insert(root,30);
	Delete(root,30);
	Inorder(root);
//	cout<<endl<<"Element "<<Search(root,8)->data<<" Present !"<<endl;
//	ISearch(root,60) ? cout<<"Element Present !"<<endl : cout<<"Element Not Present !"<<endl;
	return 0;
}
