#include<bits/stdc++.h>
using namespace std;
#define li long long int

li pmodp(li a, li b, li m){
  li y;
  if(b==0) return 1;
  if(a==0) return 0;
  if(b%2){
    y=a%m;
    y=y*pmodp(a,b-1,m);
  }
  else{
    y=pmodp(a,b/2,m);
    y=(y*y)%m;
  }
  return (li)(y+m)%m;
}
int main(){
  cout<<pmodp(100,23,607559);
}
