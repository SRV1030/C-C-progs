
// A zip line is a cable stretched between two points (upper point and lower point) of different height.

// For the Hunter Exam, Gon was asked to construct n buildings and m zip lines between some of the buildings. The description for each of the zip lines were given as (u,v), the building to which the upper point and the lower point should be attached respectively. The height of building u must be strictly greater than the height of building v.

// Now, Gon asked you whether it is possible to construct the buildings that satisfies the above conditions such that the height of each building is between 1 and n (inclusive). If it is possible, he also wants to know the height of each building.

// If there are multiple answers, you may print any.

// Input
// The first line contains a single integer t (1≤t≤105)− the number of testcases.

// Then the descriptions of t testcases follow.

// The first line of each testcase contains two space separated integers n and m (2≤n≤105, 1≤m≤min(105,n (n−1)) — the number of buildings and zip lines respectively.

// For each testcase, the next m lines contains two space separated integers u and v (1≤u≤n, 1≤v≤n, u≠v) — the building to which the upper point and the lower point should be attached respectively.

// It is guaranteed that the ordered pair (u,v) does not come more than once in each testcase.

// The sum of n and m across all testcases does not exceed 6⋅105.

// Output
// For each testcase, if it is impossible to construct the buildings that satisfies the condition, print "NO". (without quotes)

// Otherwise print "YES" and in the next line print n space separated integers, where the i-th integer is the height of the i-th building. Each integer should be in the range [1,n].

// Example
// inputCopy
// 2
// 5 4
// 1 2
// 3 4
// 1 3
// 2 4
// 2 2
// 1 2
// 2 1
// outputCopy
// YES
// 5 3 3 1 2
// NO

#include <bits/stdc++.h>
#define li long long int
#define lp(i,a,b) for(li i=a;i<b;i++)
#define rlp(i,b,a) for(li i=b;i>=a;i--)
using namespace std;
const li inf = 1e18+7;
const li ninf =-1e18+7;
const li md = 1e9+7;
bool cycle;
void dfs(int u,vector<li> &vis,vector<li>v[],vector<li> &h){
    if(cycle) return;
    vis[u]=1;
    h[u]=1;
    for(auto i:v[u]){
        if(vis[i]==1) cycle=true;
        if(!vis[i]) dfs(i,vis,v,h);
        h[u]=max(h[i]+1,h[u]);
    }
    vis[u]=2;
}

void solve(){
    li n,e;
    cin>>n>>e;
    vector<li>h(n,0);
    vector<li>v[n];
    lp(i,0,e){
        li x,y;
        cin>>x>>y;
        // cout<<x<<y;
        v[x-1].push_back(y-1);
    }
    vector<li>vis(n,0);
    cycle=false;
    lp(i,0,n) if(!vis[i]) dfs(i,vis,v,h);
    if(cycle){
        cout<<"NO"<<"\n";
        return;
    }
    else{
        cout<<"YES"<<"\n";
        lp(i,0,n)cout<<h[i]<<" ";
    }
    cout<<'\n';
    
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
