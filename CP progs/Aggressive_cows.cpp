#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
bool possible(li m,li a[],li n,li k){
    li pos=a[0];
    li e=1;
    lp(i,1,n){
        if(a[i]-pos>=m){
            pos=a[i];
            e++;
            if(e==k) return true;    
        }
    }
    return false;
}
void solve(){
    li n,k,res=1;
    cin>>n>>k;
    li a[n];
    lp(i,0,n) cin>>a[i];
    sort(a,a+n);
    li l=1,r=a[n-1]-a[0];
    while (l<r){
        li  m=(l+r)/2;
        if(possible(m,a,n,k)){
            res=max(res,m);
            l=m+1;
        }
        else r=m;
    }    
    cout<<res<<"\n";
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