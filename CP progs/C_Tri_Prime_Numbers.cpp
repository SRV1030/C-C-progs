#include <bits/stdc++.h>
#define li unsigned long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n,c=0;
    cin>>n;
    for(li i=2;i*i<=n;i++){
    if (n%i == 0) 
        { c++;
        if (n/i == i) c++;
        if(c>1) break;        
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    }
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