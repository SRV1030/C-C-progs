#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,x,a=0,b=2;
    cin>>n>>x;
    li e=x;
    while(1){
        a+=n/x; 
        if(n/x==0) break;       
        x=pow(e,b);
        b++;
        
    }
    cout<<a<<"\n";

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