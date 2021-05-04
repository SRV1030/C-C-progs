#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,d,f=0;
    cin>>n>>d;
    vector<li>v(n);
    for(auto  &it:v){
        cin>>it;
        if(it>d) f=1;
    }
    if(f==0) cout<<"YES"<<"\n";
    else{
        sort(v.begin(),v.end());
       lp(i,1,v.size()){
           if(v[i-1]+v[i]<=d){
               cout<<"YES"<<"\n";
               return;
           }

       }
       cout<<"NO"<<"\n";
    }
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
