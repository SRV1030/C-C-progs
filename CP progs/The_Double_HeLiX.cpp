#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


void solve(){
    li n,m;
    cin>>n;
    while(n!=0){
        li a[n];
        lp(i,0,n) cin>>a[i];
        cin>>m;
        li b[m];
        lp(i,0,m) cin>>b[i];
        li i=0,j=0,s1=0,s2=0,sum=0;
        while (1){
            if(i<n && j<m && a[i]<b[j]){
                s1+=a[i];
                i++;
            }
            else if(i<n && j<m && b[j]<a[i]){
                s2+=b[j];
                j++;
            }
             else if(i<n && j<m && a[i]==b[j]){
                sum+=max(s1+a[i],s2+b[j]);
                s1=0;
                s2=0;
                i++;
                j++;
            }
            if(i>=n && j>=m) break;
            if(i>=n){
                while(j<m){
                    s2+=b[j];
                    j++;
                }
                sum+=max(s1,s2);
                break;
            }
            if(j>=m){
                while(i<n){
                    s1+=a[i];
                    i++;
                }
                sum+=max(s1,s2);
                break;
            }
        }
        cout<<sum<<"\n";
        cin>>n;
        
    }
    
}
int main()
{   ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // li t=1;
    // cin>>t;
    // while(t--){
        solve();
//    }

    return 0;
}
