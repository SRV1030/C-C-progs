
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
 int size;
 int top;
 char *s;
};
void CreateStack(struct Stack *p,int size){
    p->top=-1;
    p->size=size;
    p->s=(char *)malloc(p->size*sizeof(char));
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

void Push(struct Stack *st,char x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->s[st->top]=x;
 }

}
char Pop(struct Stack *p){
    char x;
    if(isEmpty(p)) {
        printf("Stack Underflow");
    }
    else{
    x= p->s[p->top];
    p->top--;
    }
    return x;
}
char Peek(struct Stack *p,char i){
    char x;
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
int pres(char x){
    if(x=='+' || x=='-') return 1;
    else if(x=='/' || x== '*') return 3;
    return 0;
}
int isOperand(char x){
    if((x>='A' && x<='Z') || (x>='a' && x<='z')) return 1;
    else return 0;
}


char* InToPost(char*infix){
    struct Stack St;
    CreateStack(&St,strlen(infix));
    char *postfix;
    postfix=(char *)malloc(sizeof(char)*strlen(infix));
    int i=0,j=0;
    while (infix[i]!='\0'){
        if(isOperand(infix[i])) postfix[j++]=infix[i++];
        else{
            if(St.top==-1) Push(&St,infix[i++]);
            else if(pres(infix[i])>pres(St.s[St.top])) Push(&St,infix[i++]);
            else postfix[j++]=Pop(&St);
        }
    }
    while(!isEmpty(&St)){
        postfix[j++]=Pop(&St);
    }
    postfix[j]='\0';
    return postfix;
}


int main()
{
    char *infix="a+b*c-d/e";
    char *postfix=InToPost(infix);
    printf("%s ",postfix);
    return 0;

}
