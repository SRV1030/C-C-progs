#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
// const li inf = 1e18+7;
li md = 1e9+7;
void solve(){
    li n;
    cin>>n;
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=6 && i-j>=0;++j) dp[i]=(dp[i]+dp[i-j])%md;
    cout<<dp[n];
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    li t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}