#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

// https://dmoj.ca/problem/ccc20s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  double spd = 0;
  map<int,int> mii;
  cin>>n;
  for(int i = 0, t, x; i<n; i++){
    cin>>t>>x;
    mii[t] = x;
  }
  for(auto pii = mii.begin(); pii != mii.end(); pii++){
    spd = max(spd, 1.0*abs(next(pii)->second - pii->second)/(next(pii)->first - pii->first));
  }
  cout<<fixed<<setprecision(1);
  cout<<spd<<"\n";
}