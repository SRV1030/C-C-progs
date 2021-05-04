#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

void merge(int a[],int l,int r,int m){
    int i,j,k;
    int n1= m-l+1;
    int n2= r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++) L[i]=a[l+i];
    for(j=0;j<n2;j++) R[j]=a[m+1+j];
    i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]) a[k++]=L[i++];
        else if (L[i]>R[j]) a[k++]=R[j++];
        else{
            a[k++]=R[j++];
            i++;
        }
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,r,m);
    }
}
int main(){
    int a[]={1,2,33,22,43,0};
    int n= 6;
    mergesort(a,0,n-1);
    for(int j=0;j<n;j++) printf("%d ",a[j]);
}
// int main()
// {
//     int*a,n;
//     printf("Enter the array size \n");
//     scanf("%d",&n);
//     a=(int *)malloc(sizeof(int)*n);
//     printf("Enter the array: \n");
//     for(int i=0;i<n;i++) scanf("%d",&a[i]);
//     mergeSort(a,0,n-1);
//     printf("Sorted array: \n");
//     for(int i=0;i<n;i++) printf("%d ",a[i]);
//     return 0;
// }
