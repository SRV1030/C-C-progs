#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int Evaluation(char *postfix){
     struct Stack St;
     CreateStack(&St,strlen(postfix));
     for(int i=0;postfix[i]!='\0';i++){
         if(postfix[i]>='0' && postfix[i]<='9') Push(&St,postfix[i]-'0');
         else{
            int x2=Pop(&St),x1=Pop(&St);
            switch (postfix[i]){
                case '-': Push(&St,x1-x2);
                          break;
                case '+': Push(&St,x1+x2);
                          break;
                case '/': Push(&St,x1/x2);
                          break;
                case '*': Push(&St,x1*x2);
                          break;

            }
         }
     }
    return Pop(&St);

}


int main()
{
    char *infix="35*62/+4-";
    printf("%d ",Evaluation(infix));
    return 0;

}
