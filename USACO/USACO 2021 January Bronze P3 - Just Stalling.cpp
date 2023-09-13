#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/usaco21janb3

int n,c;
int s = 0;
long long ans = 1;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  vector<int> stall;
  vector<int> height;

  for(int i = 0; i<n; i++){
    cin>>c;
    height.push_back(c);
  }
  for(int i = 0; i<n; i++){
    cin>>c;
    stall.push_back(c);
  }
  sort(height.begin(),height.end());
  sort(stall.begin(),stall.end());
  
  for(int i = 0; i<n; i++){
    while(s < n && stall[n-s-1] >= height[n-i-1]) s++;
    ans *= s - i;
  }
  cout<<ans<<"\n";  
}