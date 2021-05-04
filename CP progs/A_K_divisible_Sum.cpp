#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li a,b;
    cin>>a>>b;
    if(b<a){
        li x=(a+b-1)/b;
        b*=x;
        cout<<(b+a-1)/a<<"\n";
    }else cout<<(b+a-1)/a<<"\n";
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
