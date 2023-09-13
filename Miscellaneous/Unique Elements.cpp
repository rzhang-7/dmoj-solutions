#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/set

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,x;
  unordered_set<int> num;
  cin>>n;
  while(n--){
    cin>>x;
    num.insert(x);
  }
  cout<<num.size()<<"\n";
}