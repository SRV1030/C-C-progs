#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
// const li inf = 1e18+7;
li md = 1e9+7;
void solve(){
    li n,a;
    cin>>n>>a;
    vector<int>coins(n);
    lp(i,0,n)cin>>coins[i];
    vector<int>dp(a+1,INT_MAX-1);
    dp[0]=0;
    for(int i=1;i<=a;i++)
        for(int j=0;j<n;j++)
            if(i-coins[j]>=0) dp[i]=min(dp[i],dp[i-coins[j]]+1);        
    li v= dp[a]==INT_MAX-1?-1:dp[a];
    cout<<v;
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