 https://github.com/MAZHARMIK/Interview_DS_Algo
 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int josephus(int n, int k);

int main() {

	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k

		//calling josephus() function
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}// } Driver Code Ends

void solve(vector<int>v,int k,int ind,int &ans){
    if(v.size()==1){
        ans=v[0];
        return;
    }
    ind=(ind+k)%v.size();
    v.erase(v.begin()+ind);
    solve(v,k,ind,ans);
}
/*You are required to complete this method */
int josephus(int n, int k)
{
   vector<int>v;
   for(int i=0;i<n;i++) v.push_back(i+1);
   int ans=-1;
   int ind=0;
   k--;
   solve (v,k,ind,ans);
   return ans;
}
