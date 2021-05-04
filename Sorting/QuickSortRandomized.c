#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[],int l,int h){
    int i=l-1;
    int pivot=a[h];
    for(int j=l;j<=h-1;j++){
        if(a[j]<pivot){
            i++;
            Swap(&a[i],&a[j]);
        }
    }
    Swap(&a[i+1],&a[h]);
    return (i+1);
}
int partition_r(int a[], int l, int h)
{
    srand(time(0));
    int random = l + rand() % (h - l);
    Swap(&a[random], &a[h]);
    return partition(a, l, h);
}
void QuickSort(int a[],int l,int h){
    if(l<h){
    int pi=partition_r(a,l,h);
    QuickSort(a,l,pi-1);
    QuickSort(a,pi+1,h);
    }
}
int main()
{
    int a[]={1,33,2,44,5,0,3};
    int n=sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
