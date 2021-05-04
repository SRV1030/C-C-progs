#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    cin>>n;
    if(n%2){
        li x,y;
        lp(i,0,n) cin>>x>>y;
        cout<<1<<"\n";
    }
    else{
        li x[n+1],y[n+1];
        lp(i,0,n)cin>>x[i]>>y[i];
        sort(x,x+n);
        sort(y,y+n);
        li a=x[n/2]-x[n/2-1]+1;
        li b=y[n/2]-y[n/2-1]+1;

        cout<<a*b<<"\n";
    }
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