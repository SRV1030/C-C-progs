#include <stdio.h>
#include <stdlib.h>
struct DLLNode
{
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
struct myStack
{
    struct DLLNode *head;
    struct DLLNode *mid;
    int count;
};

struct myStack *createMyStack()
{
    struct myStack *ms =
               (struct myStack*) malloc(sizeof(struct myStack));
    ms->count = 0;
    return ms;
};
void push(struct myStack *ms, int new_data)
{

    struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    new_DLLNode->data  = new_data;
    new_DLLNode->prev = NULL;
    new_DLLNode->next = ms->head;
    ms->count += 1;
    if (ms->count == 1)
    {
         ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;

        if (ms->count & 1)
           ms->mid = ms->mid->prev;
    }
    ms->head  = new_DLLNode;
}
int pop(struct myStack *ms)
{
    if (ms->count  ==  0)
    {
        printf("Stack is empty\n");
        return -1;
    }

    struct DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;

    if (!((ms->count) & 1 ))
        ms->mid = ms->mid->next;

    free(head);

    return item;
}
int delMiddle(struct myStack *ms)
{
    if (ms->count  ==  0)
    {
        printf("Stack is empty\n");
        return -1;
    }

    struct DLLNode *mid = ms->mid;
    int item = mid->data;
    mid->prev->next= mid->next;
    mid->next->prev=mid->prev;
    ms->count -= 1;
    free(mid);
    return item;
}

void DisplayStack(struct myStack *ms){
     struct DLLNode *t=ms->head;
       for(int i=0;i<ms->count;i++) {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
void entMiddle(struct myStack *ms,int x)
{
    int c1=ms->count;
    int a[(c1/2)+1];
    for(int i=0;i<c1/2;i++) a[i]=pop(ms);
    push(ms,x);
   // printf("%d ",c2);
   for(int i=c1/2-1;i>=0;i--) push(ms,a[i]);
}
int main()
{
    struct myStack *ms = createMyStack();
    push(ms, 1);
    push(ms, 2);
    push(ms, 3);
    push(ms, 4);
    push(ms, 5);
    push(ms, 99);
    DisplayStack(ms);;
    printf(" Mid Element is %d\n", delMiddle(ms));
    printf(" After deleting mid element the stack is\n");
    DisplayStack(ms);
    printf(" Enter new middle element\n");
    int i;
    scanf("%d",&i);
    entMiddle(ms,i);
     DisplayStack(ms);
    return 0;
}
