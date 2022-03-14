#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    lp(i,0,n)cin>>a[i];
    int zc=1,oc=1,ans=1;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            if(a[i])oc++;
            else zc++;
            if(zc>=2){
                cout<<-1<<"\n";
                return;
            }
        }else{
            if(zc>=2){
                cout<<-1<<"\n";
                return;
            }
            if(a[i]) ans+=(5*(oc-1))+1;
            oc=1;
            zc=1;
        }
    }
    if(zc>=2){
        cout<<-1<<"\n";
        return;
    }
    if(a[n-1]) ans+=(5*(oc-1))+1;
    cout<<ans<<"\n";
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