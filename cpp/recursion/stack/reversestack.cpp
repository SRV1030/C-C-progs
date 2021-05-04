#include<bits/stdc++.h>
using namespace std;

void Insert(stack<int> &v,int k){
    if(v.empty()) {
        v.push(k);
        return;
    }
    int temp=v.top();
    v.pop();
    Insert(v,k);
    v.push(temp);
    return;
}
void Reverse(stack<int> &v){
    if(v.size()==1) return;
    int t=v.top();
    v.pop();
    Reverse(v);
    Insert(v,t);
    return;
}
void PrintStack(stack<int> v){
    if(v.empty()) return;
    int s=v.top();
    v.pop();
    PrintStack(v);
    cout<<s<<" ";
    v.push(s);
}
int main(){
    stack <int> v;
    v.push(1);
     v.push(3);
      v.push(2);
       v.push(0);
       v.push(33);
    Reverse(v);
    PrintStack(v);

}
