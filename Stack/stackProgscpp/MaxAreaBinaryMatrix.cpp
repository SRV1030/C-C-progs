#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
vector<int> NSLI(vector<int> v){//NearestSmallestLeftIndex
    vector<int>ans;
    stack<pair<int,int>>s;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(s.size()==0) ans.push_back(-1);
        else if(s.size()>0 && v[i]>s.top().first) ans.push_back(s.top().second);
        else if(s.size()>0 && v[i]<=s.top().first){
            while(s.size()>0 && v[i]<=s.top().first) s.pop();
            if(s.size()>0) ans.push_back(s.top().second);
            else ans.push_back(-1);
        } ;
        s.push({v[i],i});
    }
    return ans;
}
vector<int> NSRI(vector<int> v){//NearestSmallestRightIndex
    vector<int>ans;
    stack<pair<int,int>>s;
    int n=v.size();
    for(int i=n-1;i>=0;i--){
        if(s.size()==0) ans.push_back(n);
        else if(s.size()>0 && v[i]>s.top().first) ans.push_back(s.top().second);
        else if(s.size()>0 && v[i]<=s.top().first){
            while(s.size()>0 && v[i]<=s.top().first) s.pop();
            if(s.size()>0) ans.push_back(s.top().second);
            else ans.push_back(n);
        };
        s.push({v[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
int MaxAreaHistogram(vector<int> v){
    vector<int>Left=NSLI(v);
    vector<int>Right=NSRI(v);
    int n=v.size();
    int mx=-100;
    for(int i=0;i<n;i++){
        int b=Right[i]-Left[i]-1;
        int l=v[i];
        int area=l*b;
        mx=max(mx,area);
    }
    return mx;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    vector<int>v;
    for(int i=0;i<m;i++) v.push_back(M[0][i]);
    int mx=MaxAreaHistogram(v);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==0) v[j]=0;
            else{
                v[j]=v[j]+M[i][j];
            }
        }
      mx=max(mx,MaxAreaHistogram(v));
    }
    return mx;
}
