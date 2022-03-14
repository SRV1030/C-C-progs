#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;

void solve(){
    string s;
    cin>>s;
    int nc=0;
    for(auto&i:s){
        if(i=='N')nc++;
        if(nc>1){
            cout<<"YES"<<"\n";
            return;
        }
    }
    if(nc==0){
            cout<<"YES"<<"\n";
            return;
    }
     cout<<"NO"<<"\n";
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
