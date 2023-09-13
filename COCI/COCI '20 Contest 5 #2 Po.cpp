#include <iostream>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/coci20c5p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin>>n;
  int arr[n];
  stack<int> seq;
  seq.push(0);  
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  for(int i = 0; i<n; i++){
    while(arr[i] < seq.top()){
      seq.pop();
    }
    if(arr[i] > seq.top()){
      ans++;
      seq.push(arr[i]);
    }
  }
  cout<<ans<<"\n";
}