#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/oly20practice24

bool cmp(int x, int y){
  return abs(x) < abs(y);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int T, N, target = 0, ans = 0;
  cin>>T>>N;
  vector<int> arr;
  for(int i = 0, x; i<N; i++){
    cin>>x;
    arr.push_back(x);
  }
  arr.push_back(0);
  sort(arr.begin(), arr.end(), cmp);
  for(int i = 1; i<(int)arr.size(); i++){
    target += abs(arr[i] - arr[i-1]);
    if(target > T) break;
    ans++;
  }
  cout<<ans<<"\n";
}