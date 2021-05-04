#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    string a,b,c="",d="";
    cin>>a>>b;
    if(a==b){
        cout<<a<<"\n";
        return;
    } 
    li x=a.length(),y=b.length();
    li lc=(x*y)/(__gcd(x,y));
    x=lc/x;
    y=lc/y;
    while (x--)      
       c+=a;
    while (y--)      
       d+=b;
    if(c==d) cout<<c<<"\n";
    else  cout<<-1<<"\n";

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
