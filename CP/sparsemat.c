#include <stdio.h>
#include <stdlib.h>

struct element{
    int r;
    int c;
    int val;
};
struct sparse{
    int m;
    int n;
    int num;
    struct element *ele;
};
 void printsp(struct sparse s){
     int k=0;
     for(int i=0;i<s.m;i++){
         for(int j=0;j<s.n;j++){
             if(i==s.ele[k].r && j==s.ele[k].c){
                  printf("%d ",s.ele[k].val);
                    k+=1;
             }
             else printf("0 ");
         }
         printf("\n");
     }
    // for(int i=0;i<s.num;i++) printf("%d ",s.ele[i].val);
 }
struct sparse *spadd(struct sparse *s1,struct sparse *s2){
     int i=0,j=0;
     struct sparse *add;
     add= (struct sparse *)malloc(sizeof(struct sparse));
     add->m=s1->m;
     add->n=s1->n;
     add->num=0;
     add->ele =(struct element *)(malloc(10 * sizeof(struct element)));
     while(i<s1->num && j<s2->num){
      if(s1->ele[i].r < s2->ele[j].r){
          add->ele[add->num]=s1->ele[i++];
          add->num+=1;
      }
      else if(s1->ele[i].r > s2->ele[j].r){
         add->ele[add->num]=s2->ele[j++];
         add->num+=1;
      }
      else{
        if(s1->ele[i].c < s2->ele[j].c){
          add->ele[add->num]=s1->ele[i++];
          add->num+=1;
        }
      else if(s1->ele[i].c > s2->ele[j].c){
         add->ele[add->num]=s2->ele[j++];
         add->num+=1;
        }
      else{
         add->ele[add->num]=s2->ele[j++];
         add->ele[add->num].val+=s1->ele[i].val;
         add->num+=1;
         i++;
        }
      }
    }
    while(i<s1->num){
        add->ele[add->num]=s1->ele[i++];
         add->num+=1;
    }
    while(j<s2->num){
        add->ele[add->num]=s2->ele[j++];
         add->num+=1;
    }
    return add;

 }


int main()
{
    int m=3,n=4;
    int a[][4]={
            {12,0,3,0},
            {2,0,2,0},
            {1,0,3,0},
            };
    int b[][4]={
            {1,0,3,0},
            {2,1,2,0},
            {1,0,3,0},
            };
    struct sparse s1,s2,*s3;
    s2.m=s1.m=3;
    s2.n=s1.n=4;
    s1.num=0;
    s1.ele=(struct element *)(malloc(10 * sizeof(struct element)));
    s2.ele=(struct element *)(malloc(10 * sizeof(struct element)));
    for(int i=0;i<m;i++){
         for(int j=0;j<n;j++)
             if(a[i][j]!=0){
                 s1.ele[s1.num].r=i;
                 s1.ele[s1.num].c=j;
                 s1.ele[s1.num].val=a[i][j];
                s1.num+=1;
             }
         }
    s2.num=0;
    for(int i=0;i<m;i++){
         for(int j=0;j<n;j++)
             if(b[i][j]!=0){
                 s2.ele[s2.num].r=i;
                 s2.ele[s2.num].c=j;
                 s2.ele[s2.num].val=b[i][j];
                s2.num+=1;
             }
         }
    s3=spadd(&s1,&s2);
    printsp(*s3);
    return 0;
}
