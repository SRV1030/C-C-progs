#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    string s;
    cin>>s;
    n=s.size();
    stack<char>v;
    lp(i,0,n){
        if(s[i]=='A') v.push('A');
        else{
            if(v.size()>0)v.pop();
            else v.push('B');
        }
    }
    cout<<v.size()<<"\n";
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