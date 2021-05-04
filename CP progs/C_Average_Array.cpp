#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
   li n,x=0,s=0,b=0;
   cin>>n;
   lp(i,0,n){
       cin>>x;
       b=x*(i+1)-s;
       cout<<b<<" ";
       s+=b;
   }
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