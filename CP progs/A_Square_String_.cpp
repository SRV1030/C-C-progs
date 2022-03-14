#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(n%2) cout<<"NO"<<"\n";
    else{
        if(s.substr(0,n/2)==s.substr(n/2)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
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
