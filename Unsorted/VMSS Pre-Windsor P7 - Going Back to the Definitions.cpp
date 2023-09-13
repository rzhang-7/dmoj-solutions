#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/pwindsor18p7

const int MM = 1e4;

int n;
string ans, arr[MM];

bool cmp(string a, string b){
  return a+b > b+a;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr+n, cmp);
  for(int i = 0; i<n; i++){
    ans += arr[i];
  }
  cout<<ans<<"\n";
}