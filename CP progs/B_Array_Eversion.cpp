#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    int n;
    cin>>n;
    li a[n],mx=LONG_MIN;
    lp(i,0,n){
        cin>>a[i];
        if(a[i]>mx)mx=a[i];
    }
    if(a[n-1]==mx){
        cout<<0<<"\n";
        return;
    }
    li c=1,cmx=a[n-1];
    rlp(i,n-2,0){
        if(a[i]==mx) break;
        if(a[i]>cmx){
            c++;
            cmx=a[i];
        }
    }
    cout<<c<<"\n";    
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
