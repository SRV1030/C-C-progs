#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define li long int
#define lp(i,a,b) for(li i=a;i<b;i++)
void display(li *a,int n){
    lp(i,0,n) printf("%ld ",a[i]);
    printf("\n");
}

void insertion(li *a,li n){
    li i,j,k;
    i=j=k=0;
    lp(i,1,n){
       k=a[i];
       j=i-1;
       while(j>=0&&a[j]>k){
           a[j+1]=a[j];
           j-=1;
       }
       a[j+1]=k;
    }
}
void swap(li *xp, li *yp)
{
    li temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection(li* a,li n){
    li id,f=0;
    lp(i,0,n-1){
        id=i;
        lp(j,i+1,n){
            if(a[id]>a[j]){
                id=j;
                f=1;
            }
        }
        if(f) swap(&a[i],&a[id]);
    }
}

void bubble(li* a,li n){
    li flag=1;
    lp(i,0,n-1)
        lp(j,0,n-1){
          if ( a[j] > a[j+1] ){
            swap(&a[j],&a[j+1] );
            flag=0;
          }
          if(flag) break;
        }
}

int main()
{  li n,v,o;
    clock_t start,end;
    li *b,*c,*a;
    int ss;
    printf("Enter the 1 for sorted array in ascending order.\nEnter the 2 for sorted array in descending order.\nEnter the 3 for array in random order.\nEnter 4 to exit. \n");
    printf ("Enter the desired array type: ");
    scanf("%d",&ss);
    while(ss!=4)
    {switch (ss){
        case 1: printf("Enter the size of array");
                scanf("%ld",&n);
                a=(li*)(malloc(sizeof(li)*n));
                b=(li*)(malloc(sizeof(li)*n));
                c=(li*)(malloc(sizeof(li)*n));
                lp(i,0,n) a[i]=b[i]=c[i]=i;
                goto ops;
                break;
        case 2: printf("Enter the size of array");
                scanf("%ld",&n);
                a=(li*)(malloc(sizeof(li)*n));
                b=(li*)(malloc(sizeof(li)*n));
                c=(li*)(malloc(sizeof(li)*n));
                v=n;
                lp(i,0,n) a[i]=b[i]=c[i]=v--;
                goto ops;
                break;
        case 3: printf("Enter the size of array");
                scanf("%ld",&n);
                a=(li*)(malloc(sizeof(li)*n));
                b=(li*)(malloc(sizeof(li)*n));
                c=(li*)(malloc(sizeof(li)*n));
                srand(time(0));
                lp(i,0,n) a[i]=b[i]=c[i]=(rand()%100)+2;
                goto ops;
                break;
        }
    ops:
            printf("The array is: \n");
            display(a,n);
            printf("By selsection sorting: \n");
            start=clock();
            selection(a,n);
            end=clock();
            display(a,n);
            printf("Time taken = %lf second \n",(double)(end-start)/CLOCKS_PER_SEC);
            printf("By bubble sorting: \n");
            start=clock();
            bubble(b,n);
            end=clock();
            display(b,n);
            printf("Time taken = %lf second \n",(double)(end-start)/CLOCKS_PER_SEC);
            printf("By insertion sorting: \n");
            start=clock();
            insertion(c,n);
            end=clock();
            display(c,n);
            printf("Time taken = %lf second \n",(double)(end-start)/CLOCKS_PER_SEC);
            printf ("Enter the desired array type: ");
            scanf("%d",&ss);
            if(ss==4) printf("EXIT");

    }


}
