#include <bits/stdc++.h>
#define li unsigned long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,ans;
    cin>>n;
    lp(i,0,n){
        li x;
        cin>>x;
        if(i==0)ans=x;
        else ans=(ans*x)/(__gcd(ans,x));
    }
    cout<<ans<<"\n";
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