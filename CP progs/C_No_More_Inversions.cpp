#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,k;
    cin>>n>>k;
    if(n-k==0){
        lp(i,1,k+1)cout<<i<<" ";
        cout<<"\n";
        return;
    }
    lp(i,1,k-(n-k))cout<<i<<" ";
    lp(i,1,(n-k)+2)cout<<k-i+1<<" ";
    cout<<"\n";   

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
