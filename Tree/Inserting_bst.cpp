#include<iostream>
using namespace std;

struct Node{
	Node *lchild;
	int data;
	Node *rchild;
};

class bst{
	private : 
		struct Node *root;
		void print(Node*);
	
	public : 
		bst(int);
		int insert(int);
		void traverse();
};

bst::bst(int rVal){
	root=new Node;
	root->data=rVal;
	root->lchild=root->rchild=NULL;
}

int bst::insert(int key){
	struct Node *r=NULL,*t,*p;
	t=root;
	
	while(t!=NULL){
		r=t;
		if(t->data==key) return -1;
		else if (key<t->data) t=t->lchild;
		else t=t->rchild;	
	}
	
	p=new Node;
	p->data=key;
	p->lchild=p->rchild=NULL;
	
	if(p->data < r->data) r->lchild=p;
	else r->rchild=p;
	
	return 1;
}

void bst::print(Node *t){
	
	if(t){
		print(t->lchild);
		cout<<t->data<<" ";
		print(t->rchild);
	}

}

void bst::traverse(){
	print(root);
}

int main(){
	
	bst tree1(23);
	tree1.insert(12);
	tree1.insert(34);
	tree1.insert(14);
	tree1.insert(42);
	tree1.insert(22);
	tree1.insert(62);
	tree1.insert(32);
	tree1.insert(20);
	tree1.insert(10);
	tree1.insert(78);
	tree1.traverse();
}
