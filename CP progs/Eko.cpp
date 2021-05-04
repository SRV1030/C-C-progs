#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;

void solve(){
    li n,k;
    cin>>n>>k;
    li a[n];
    lp(i,0,n) cin>>a[i];
    li l=0,h=*max_element(a,a+n),mn=0;
    while (l<=h){
        li m=l+(h-l)/2;
        li s=0;
        lp(i,0,n){
            li t=(a[i]-m);
            s+= t>0?t:0;            
        }
        if(s==k){
            mn=m;
            break;
        }
        else if(s<k){
            h=m-1;           
        }
        else{
            l=m+1;
            mn=max(mn,m);
        }
    }
    cout<<mn<<"\n";

}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
//    }

    return 0;
}