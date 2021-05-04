#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,i,j,f=0;
    li x;
    li op=0;
    cin>>n>>x;
    lp(z,0,n){
        cin>>i>>j;
        op+=i*j;

        // cout<<i<<" "<<j<<" "<<op<<" ";
        if(op>x*100){
            
            cout<<z+1<<"\n";
            return;
        }
    }
  cout<<-1<<"\n"; 
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
   // }

    return 0;
}