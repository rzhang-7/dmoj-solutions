#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/usaco20decb2

const int MM = 101;

int n, ans, arr[MM];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  for(int i = 1; i<=n; i++)
    cin>>arr[i];
  for(int i=1; i<=n; i++){
    unordered_set<int> s;
    for(int j=i, sum=0; j<=n; j++){
      sum += arr[j];
      s.insert(arr[j]);
      int idx = j-i+1;
      if(sum % idx == 0 && s.count(sum/idx)) ans++;
    }
  }
  cout<<ans<<"\n";
}