#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    cin>>n;
    li a[n];
    lp(i,0,n)cin>>a[i];
    li ff=0;
    lp(i,0,n-1){
        li x=0;
        lp(j,0,i+1) x^=a[j];
        li t=0,f=0;
        lp(j,i+1,n){
            t^=a[j];
            if(t==x){
                t=0;
                f=1;
            }
        }
        if(t==0 && f){
            cout<<"YES"<<"\n";
            ff=1;
            break;
        }

    }
     if(!ff)cout<<"NO"<<"\n";
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