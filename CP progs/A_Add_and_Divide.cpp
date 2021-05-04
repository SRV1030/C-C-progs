#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li a,b;
    cin>>a>>b;
    li c=0,mn=inf;
    for(li i=0;i*i<=a;i++){
        if(i==0 && b==1) continue;
        c=a;
        li ans=0;
        while(c){
            c=c/(b+i);
            ans++;
        }
        mn=min(mn,ans+i);
    }
    
    cout<<mn<<"\n";
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