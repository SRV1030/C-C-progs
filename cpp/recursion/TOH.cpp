#include <bits/stdc++.h>
using namespace std;
void TOH(int s,int d, int h,int n){
    if(n==1){
        std::cout << "Move plate at index " << n <<" from "<<s <<" to " << d << std::endl;
        return;
    }
    TOH(s,h,d,n-1);
    std::cout << "Move plate at index " << n <<" from "<<s <<" to " << d << std::endl;
    TOH(h,d,s,n-1);
    return;
}
int main()
{
    TOH(1,3,2,3);

    return 0;
}
