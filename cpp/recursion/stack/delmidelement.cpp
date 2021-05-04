#include<bits/stdc++.h>
using namespace std;

void MidDel(stack<int> &v,int k){
    if(k==1) {
        v.pop();
        return;
    }
    int temp=v.top();
    v.pop();
    MidDel(v,k-1);
    v.push(temp);
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
    MidDel(v,(v.size()/2)+1);
    PrintStack(v);

}
