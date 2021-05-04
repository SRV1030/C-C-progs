#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,k;
    cin>>n>>k;
    li h[n];
    lp(i,0,n)cin>>h[i];
    li p=0,f=0;
    while(k>0 && p<n){
        li stop=0;
        lp(i,0,n-1){
            if(h[i]<h[i+1]){
                k--;
                stop=1;
                h[i]+=1;
                p=i;
                break;
            }
        }
        if(stop) continue;
        else{
            cout<<-1<<"\n";
            f=1;
            break;
        }
    }
    if(!f) cout<<p+1<<"\n";
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
