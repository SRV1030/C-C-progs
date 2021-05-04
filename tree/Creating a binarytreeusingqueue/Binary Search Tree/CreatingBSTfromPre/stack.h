struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
};

struct Stack{
    int top;
    int size;
    struct Node **S;
};

void CreateStack(struct Stack *st,int size){
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(sizeof(struct Node*)*size);
}

void Push(struct Stack *st,struct Node* data){
    if(st->top+1==st->size){
        printf("Stack full");
        return;
    }
    st->top++;
    st->S[st->top]=data;
}
struct Node* Pop(struct Stack *st){
    struct Node *x=NULL;
    if(st->top==-1){
        printf("Stack empty");
        return x;
    }
    x=st->S[st->top--];
    return x;
}
int isEmptyStack(struct Stack st){
    return st.top==-1;
}
struct Node* StackTop(struct Stack *st){

if(!isEmptyStack(*st))

return st->S[st->top];

else return NULL;

}