#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    string s;
    cin>>s;
    li n=s.size();
    if((s[n-1]-'0')%2==0) cout<<0<<"\n";
    else{
        lp(i,0,n-1){
            if((s[i]-'0')%2==0){
                if(!i)cout<<1<<"\n";
                else cout<<2<<"\n";
                return;
            } 
        }
      cout<<-1<<"\n"; 
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