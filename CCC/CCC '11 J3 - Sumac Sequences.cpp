#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc11j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t1, t2;
  vector<int> ans;
  cin>>t1>>t2;
  ans.push_back(t1);
  while(t1 - t2 >= 0){
    t2 = t1 - t2;
    t1 -= t2;
    ans.push_back(t1);
  }
  ans.push_back(t2);
  cout<<ans.size()<<"\n";
}