#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;

void solve(){
    li n;
    cin>>n;
    unordered_map<li,li> mp;
    while(n--){
        li x;
        cin>>x;
        mp[x]++;
    }
    for(auto&i:mp){
        if(i.second%i.first){
                cout<<"NO"<<"\n";
                return;
            }
    }
    cout<<"YES"<<"\n";
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