#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc22c5p2

ll n, neg;
vector<int> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  neg = (n+1)*n/4;
  for(int i = 1; i<=n; i++){
    int num = n - i + 1;
    if(num <= neg){
      v.push_back(-n);
      neg -= num;
    } else {
      v.push_back(-neg);
      break;
    }
  }
  while(v.size()<n) v.push_back(1);
  for(int i = 0; i<n; i++){
    cout<<v[i]<<" \n"[i==n-1];
  }
} 