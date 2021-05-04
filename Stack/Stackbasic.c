#include <stdio.h>
#include <stdlib.h>

struct Stack
{
 int size;
 int top;
 int *s;
};
void CreateStack(struct Stack *p,int size){
    p->top=-1;
    p->size=size;
    p->s=(int *)malloc(p->size*sizeof(int));
}

int isEmpty(struct Stack *p){
    if(p->top==-1) return 1;
    else return 0;
}

int isFull(struct Stack *p){
    if(p->size-1==p->top) return 1;
    else return 0;
}

int StackTop(struct Stack *p){
    if(p->top==-1) return-1;
    else return p->s[p->top];
}

void Push(struct Stack *st,int x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->s[st->top]=x;
 }

}
int Pop(struct Stack *p){
    int x;
    if(isEmpty(p)) {
        printf("Stack Underflow");
    }
    else{
    x= p->s[p->top];
    p->top--;
    }
    return x;
}
int Peek(struct Stack *p,int i){
    int x;
    if((p->top-i+1)<0) {
        printf("Invalid Index");
    }
    else x=p->s[p->top-1+1];
    return x;
}
void PrintStack(struct Stack *p){
    for(int i=p->top;i>=0;i--){
        printf("%d ",p->s[i]);
    }
    printf("\n");
}
int main()
{
    int size=5;
    struct Stack St;
    CreateStack(&St,size);
    Push(&St,0);
    Push(&St,2);
    Push(&St,1);
    Push(&St,33);
    Push(&St,12);
    PrintStack(&St);
    printf("%d\n",Pop(&St));
    PrintStack(&St);
    printf("%d ",Peek(&St,3));
    return 0;
}
