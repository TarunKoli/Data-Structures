#ifndef Stack_h
#define Stack_h
using namespace std;

//struct Node{
//	struct Node *lchild;
//	int data;
//	struct Node *rchild;
//};

struct Stack{
	int size;
	int top;
	struct Node **S;
};

void create_stack(struct Stack *s, int n){
	s->size=n;
	s->top=-1;
	s->S=(struct Node **)malloc(s->size*sizeof(struct Node *));
}

void push(struct Stack *s, Node* val){
	if(s->top == s->size-1){
		cout<<"Stack Overflow !"<<endl;
	}else{
		s->top++;
		s->S[s->top]=val;
	}
}

Node* pop(struct Stack *s){
	Node *x=NULL;
	
	if(s->top<0){
//		cout<<"Stack Underflow !"<<endl;
		return NULL;
	}else{
		x=s->S[s->top--];
	}
	return x;
}

int isStackEmpty(struct Stack s){
	return s.top==-1;
}

int isFullStack(struct Stack s){
	return s.top==s.size-1;
}

#endif
