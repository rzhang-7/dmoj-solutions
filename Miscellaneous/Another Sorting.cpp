#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/anothersorting

bool cmpU(int x, int y){
  return x%10 < y%10;
}

bool cmpD(int x, int y){
  return x > y;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> v;
  cin>>n;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    v.push_back(x);
  }
  stable_sort(v.begin(), v.end(), cmpD); // stable_sort() preserves order
  stable_sort(v.begin(), v.end(), cmpU);
  for(int i = 0; i<n; i++){
    cout<<v[i]<<(i == n-1 ? "\n" : " ");
  }
}