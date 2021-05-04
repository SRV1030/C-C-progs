#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
 char data;
 struct Node *next;
}*top=NULL;

void Push(char x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node*));
    if(t==NULL) printf("Stack is Full");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char Pop(){
    char x=-1;
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node*));
    if(top==NULL) printf("Empty Stack");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free (t);
    }
    return x;
}
void DisplayStack(){
    struct Node *t;
    t=top;
    while(t!=NULL){
        printf("%c ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main()
{
    Push('1');
    Push('2');
    Push('0');
    DisplayStack();
    printf("%c\n",Pop());
    DisplayStack();
    return 0;

}
