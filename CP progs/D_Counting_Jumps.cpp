#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    li n,k,m;
    cin>>n>>k>>m;
    vector<li>v(m,0);
    v[0]=1;
    li x= k*m;
    li c = n*k/x;
    li j=0;
    while (j<x){   
       j+=k;     
       v[j%m]+=c;
    }  
    j= x*c;
    li e= c*x/k;
    while(e<n){                    
        j+=k;    
        v[j%m]++;
        e++;
    }
    lp(i,0,m)cout<<v[i]<<" ";
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
