#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/modulosort

const int MM = 1e5;

int n, k, arr[MM];

bool cmp(int x, int y){
  return x%k < y%k || (x < y && x%k == y%k);
}

int main() {
  cin.sync_with_stdio(0); 
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n,cmp);
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" \n"[i==n-1];
  }
}