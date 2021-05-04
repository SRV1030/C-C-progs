#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    string b="1",a;
    cin>>n>>a;    
    lp(i,1,n){
        if((a[i-1]-'0')+b[i-1]-'0' != (a[i]-'0')+1 ) b.push_back('1');
        else b.push_back('0');
    }
    cout<<b<<"\n";
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