#include <bits/stdc++.h>
#define li unsigned long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li m;
    string s;
    cin>>s>>m;  
    li mod = 0;

    lp(i,0,s.size()){ 
           
        int digit = s[i] - '0';
        mod = mod * 10 + digit;         
        mod = mod % m;         
    } 
    cout<<mod<<"\n";
  
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