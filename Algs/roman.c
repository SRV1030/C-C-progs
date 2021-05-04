#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#define lp(i,a,b) for(int i=a;i<b;i++)
#define li long unsigned int
// binary converter
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}
int romanconv(char a[],int n){
    int x=0,value1,value2;
    lp(i,0,n){
        value1=value(a[i]);
        if(i+1<n){
            value2=value(a[i+1]);
            if(value1>=value2) x=x+value1;
            else {
                    x=x+value2-value1;
                    i++;
                 }
        }
        else x+=value1;
    }
    return x;
}
void romandisplay(li a){
    li i=12;
    char *R[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    li D[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    while(a>0){
        li q= a / D[i];
        a= a % D[i];
        while(q--) printf("%s",R[i]);
        i--;
    }
    printf("\n");
}
void binarydisplay(int n){
    for (int i = 31; i >= 0; i--) {
        li k = n >> i;
        if (k & 1)
            printf("%d",1);
        else
            printf("%d",0);
    }
     printf("\n");
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}


int main()
{   li n,a=0;
    printf("Enter your number in Hindu Arabic System: ");
    scanf("%lu",&n);
    while(a!=4){
    printf("\nEnter 1 to display in Binary number system.\nEnter 2 to display in Decimal number system.\nEnter 3 to display in Unary number system.\nEnter 4 to exit.\n");
    scanf("%lu",&a);
        switch(a){
            case 1:printf("The number in Roman number System is:\n");
                   romandisplay(n);
                   break;
            case 2:printf("The number in Binary number System is:\n");
                   binarydisplay(n);
                   break;
            case 3:printf("The number in Unary number System is:\n");
                   for(li i=0;i<n;i++) printf("I");
                   printf("\n");
                   break;
        }
    }if(a==4) printf("\nExit\n");

}
