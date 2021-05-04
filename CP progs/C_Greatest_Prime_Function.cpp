#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,a,b) for(li i=a;i>=b;i--)
using namespace std;
// const li inf = 1e18+7;
vector<li>Pr;

bool isPrime(li n) 
{  
    if(n==1) return false;
    if(n==2 || n==3 || n==5 || n==7||n==11) return true;
    if (n%2 == 0 || n%3 == 0) return false; 
    for(li i=5;i*i<=n;i+=6){
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    }  
    return true; 
    
}
void solve(){
    li x,y,f1,f2;
    cin>>x>>y;
    rlp(i,x,0)
        if(isPrime(i)){
            f1=i;
            break;
        }
    rlp(i,y,0)
        if(isPrime(i)){
            f2=i;
            break;
        }
    cout<<f1-f2<<"\n";
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
  // }

    return 0;
}

