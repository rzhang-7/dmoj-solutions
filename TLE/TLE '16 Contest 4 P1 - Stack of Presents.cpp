#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/tle16c4p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, sum = 0;
  stack<int> g;
  cin>>n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>>arr[i]; 
  }
  sort(arr, arr + n);
  for(int i = 0; i<n; i++){
    if(arr[i] >= sum){
      g.push(arr[i]);
      sum += arr[i];
    }
  }
  cout<<g.size()<<"\n";
}