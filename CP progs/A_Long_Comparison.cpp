#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
li power10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n]; 
}
void solve(){
    li n1,p1,n2,p2;
    cin>>n1>>p1>>n2>>p2;
    li mn=min(p1,p2);
    p1-=mn;
    p2-=mn;
    if(p1>=7) cout<<">"<<"\n";
    else if(p2>=7) cout<<"<"<<"\n";
    else{
        li x=n1*power10(p1),x2=n2*power10(p2);
        // cout<<x<<" "<<x2<<"\n";
        if(x>x2)cout<<">"<<"\n";
        else if(x<x2)cout<<"<"<<"\n";
        else cout<<"="<<"\n";
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
