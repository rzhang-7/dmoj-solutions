#include <iostream>
#include <unordered_map>
using namespace std;

// https://dmoj.ca/problem/dmopc19c6p2

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, n = INT32_MAX;
  cin>>a>>b;
  unordered_map<int,int> mp;
  while(a%2==0){
    mp[2]++;
    a /= 2;
  }
  for(int i = 3; i*i<=a; i+=2){
    while(a%i==0){
      mp[i]++;
      a /= i;
    }
  }
  if(a != 1) mp[a]++;
  for(pair<int,int> x : mp){
    int num = 0, tmp = x.first;
    while(b/tmp != 0){
      num += b/tmp;
      tmp *= x.first;
    }
    n = min(n, num/x.second);
  }
  cout<<n<<"\n";
}