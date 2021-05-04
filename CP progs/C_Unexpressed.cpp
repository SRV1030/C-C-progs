#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;

const li inf = 1e18+7;
const li ninf =-1e18+7;


bool check(int n){  
    if(n==1 || n==2 || n==3 || n==5 || n==7) return false;
    if(n%2==0){
        li c=0;
        while (n % 2 == 0){  
            n = n/2;  
            c++;
        } 
        if(n!=1 || c!=1) return false;
        return true;
    } 
    for (int i = 3; i*i <= n; i = i + 2){ 
        if(n%i==0){
        li c=0;
        while (n % i == 0){  
            n = n/i; 
            c++; 
        } 
        if(n!=1 || c!=1) return false;
        return true;
     } 
    }
    return false;
}  

void solve(){
    li n,mn=-1;
    cin>>n;
    while (n--)
    {
        li a,p,c;
        cin>>a>>p>>c;
        if(c>a){
            if(mn!=-1)mn=min(p,mn);
            else mn=p;
        }
    }
    cout<<mn<<"\n";
    
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