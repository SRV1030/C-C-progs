#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;


void solve(){
    string s,p;
    cin>>s>>p;
    li m=s.length(),n=p.length(),ans=inf;
    lp(i,0,m-n+1){
        li c=0;
        lp(j,0,n){
            if(p[j]==s[i+j])c++;
        }
        ans=min(ans,n-c);

    }
    cout<<ans<<'\n';
    
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
