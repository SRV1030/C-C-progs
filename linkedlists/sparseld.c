#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
int col;
struct Node *next;
};
struct Node *first=NULL;
void create(struct Node *A[],int m,int n,int val)
{
struct Node *p,*t;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=val;
t->next=NULL;
t->col=n;
p=A[m];
if(p==NULL)
{
A[m]=t; // mistake here
}
else
{
while(p->next!=NULL)
{
p=p->next;
}
p->next=t;
}
}
void display(struct Node *A[],int m,int n)
{
struct Node *p;
for(int i=0;i<m;i++)
{
p=A[i];
for(int j=0;j<n;j++) // mistake here. you wrote i++
{
if(p && j==p->col) // one more condition here
{
printf("%d ",p->data);
p=p->next;
}
else
{
printf("0 ");
}
}
printf("\n");
}
}

int main()
{
printf("Enter Size of Matrix\n");
int m,n;
scanf("%d%d",&m,&n); // emove space between %d
struct Node *A[m];
for(int i=0;i<m;i++)A[i]=NULL; // A should be initialised
int k;
int num;
printf("Enter no of non zero elements\n");
scanf("%d",&num);
int i,j;
printf("Row Col Val\n");
for(int w=0;w<num;w++)
{
scanf("%d%d%d",&i,&j,&k);
create(A,i,j,k);
}
display(A,m,n);
return 0;
}
