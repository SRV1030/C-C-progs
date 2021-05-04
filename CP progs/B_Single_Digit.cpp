#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
li evenSum(string s){
    li i=0,sum=0;
    for(i;i<s.length();i+=2) sum+=(s[i]-'0');
    return sum;
}
li oddSum(string s){
    li i=1,sum=0;
    for(i;i<s.length();i+=2) sum+=(s[i]-'0');
    return sum;
}
void solve(){
    string s;
    li x;
    cin>>s>>x;
    li p,q,r,z,t,u;
    p=evenSum(s);
    q=oddSum(s);
    r=evenSum(to_string(p));
    z=oddSum(to_string(p));
    t=evenSum(to_string(q));
    u=oddSum(to_string(q));
    
    if(p==x||q==x||r==x||z==x||t==x||u==x) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    
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