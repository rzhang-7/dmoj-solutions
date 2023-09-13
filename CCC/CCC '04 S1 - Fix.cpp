#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc04s1

int n;
string arr[3];

bool pre(string str, int a, int b){
  for(int i = 1; i <= (int)str.length(); i++){
    string sub = str.substr(0, i);
    if(sub == arr[a] || sub == arr[b]) return true;
  }  
  return false;
}

bool suf(string str, int a, int b){
  for(int i = str.length(); i >= 1; i--){
    string sub = str.substr(i-1, str.length()+1-i);
    if(sub == arr[a] || sub == arr[b]) return true;
  }  
  return false;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>arr[0]>>arr[1]>>arr[2];
    if(pre(arr[0],1,2) || suf(arr[0],1,2) || pre(arr[1],0,2) || suf(arr[1],0,2) || pre(arr[2],0,1) || suf(arr[2],0,1)){
      cout<<"No\n";
    } else {
      cout<<"Yes\n";
    }
  }
}