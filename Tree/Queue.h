#ifndef Queue_h
#define Queue_h
using namespace std;

struct Node{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

struct Queue{
	int size;
	int front;
	int rear;
	struct Node **Q;
};

void create(struct Queue *q, int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=(Node**)malloc(q->size*sizeof(Node*));
}

void enqueue(struct Queue *q, Node* val){
	if((q->rear+1)%q->size==q->front){
		cout<<"Queue is full !"<<endl;
	}else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=val;
	}
}

Node* dequeue(struct Queue *q){
	Node* val=NULL;
	if(q->rear==q->front){
		cout<<"Queue is empty !"<<endl;
	}else{
		q->front=(q->front+1)%q->size;
		val=q->Q[q->front];
	}
	return val;
}

int isEmpty(struct Queue q){
	return q.front==q.rear;
}

#endif
