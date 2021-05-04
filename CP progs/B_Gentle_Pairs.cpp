#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
using namespace std;
const li inf = 1e18+7;
void solve(){
    li n;
    cin>>n;
    li a[n][2];
    lp(i,0,n){
        cin>>a[i][0]>>a[i][1];
    }
    li c=0;
    lp(i,0,n-1)
     lp(j,i+1,n){
         long double s;
         s=(ceil)(a[i][1]-a[j][1])/(a[i][0]-a[j][0]);
         if(s>=-1.0 && s<=1.0){
            //  cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[j][0]<<" "<<a[j][1]<<" "<<s<<"\n";
             c++;
         }
     }
    cout<<c<<"\n";
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
