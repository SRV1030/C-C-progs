#include<bits/stdc++.h>
using namespace std;

void InserT(vector<int> &v,int temp){
    if( v.size()==0 || v[v.size()-1]<=temp ){
        v.push_back(temp);
        return;
     }
    int val=v[v.size()-1];
    v.pop_back();
    InserT(v,temp);
    v.push_back(val);
    return;
}

void Sort(vector<int> &v){
    if(v.size()==1) return;
    int temp=v[v.size()-1];
    v.pop_back();
    Sort(v);
    InserT(v,temp);
    return;
}

int main(){
    vector <int> v;
    v.push_back(1);
     v.push_back(3);
      v.push_back(2);
       v.push_back(0);
    Sort(v);
    for (auto i : v) cout<< i <<" ";

}
