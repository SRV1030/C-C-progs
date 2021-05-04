#include<bits/stdc++.h>
#define li long long int
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        li n;
        cin>>n;
        li arr[n];
        for(li i=0;i<n;i++) cin>>arr[i];
        if(n==3){
            cout<<0<<endl;
            continue;
        }
        sort(arr,arr+n);
        li ans=0;
        if(n%2==0){
            for(li i=n-1;i>=0;i--){
                ans+=arr[i]-arr[i-1];
                i-=1;
            }
        }
        else{
            for(li i=n-2;i>=0;i--){
                ans+=arr[i]-arr[i-1];
                i-=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}