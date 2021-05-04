#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

li getNum(li a,li t){
    li d=sqrt(a*a+8*t*a);
    d-=a;
    d/=2*a;
    return d;
}

bool isPoss(li a[],li n,li t,li p){
    li c=0;
    lp(i,0,n){
        c+=getNum(a[i],t);
        if(c>=p) return true;
    }    
    return false;
}

void solve(){
    li p,n;
    cin>>p>>n;
    li a[n];
    lp(i,0,n) cin>>a[i];
    sort(a,a+n);
    li l=0,h=((p*(p+1))/2)*a[0];
    while (l<=h){
        li m=l+(h-l)/2;
        if(isPoss(a,n,m,p)){
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    li t=1;
    cin>>t;
    while(t--){
        solve();
   }

    return 0;
}
