#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,a,b) for(li i=a;i>=b;i--)
using namespace std;
// const li inf = 1e18+7;

void solve(){
    li n;
    cin>>n;
    li k=1;
    while((k*(k+1))<2*n) k++;
    cout<<k<<"\n";

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

