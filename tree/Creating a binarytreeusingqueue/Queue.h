struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
};
struct Queue{
    int front;
    int rear;
    int size;
    struct Node **Q;
};
void createQueue(struct Queue *q,int size){
    q->front=0;
    q->rear=0;
    q->size=size;
    q->Q=(struct Node **)malloc(sizeof(struct Node*)*size);
}
void Enqueue(struct Queue *q,struct Node *x){
    if((q->rear+1)%q->size==q->front) printf("Full Queue");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * Dequeue(struct Queue *q){
    struct Node *x=NULL;
    if(q->front==q->rear){
        printf("Empty Queue");
        return x;
    }
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}


