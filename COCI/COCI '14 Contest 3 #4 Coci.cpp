#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci14c3p4

const int MM = 651;

int n, psa[MM+1][MM+1];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  vector<int> x(n), y(n);
  for(int i = 0; i<n; i++){
    cin>>x[i]>>y[i]; x[i]++; y[i]++;
    psa[x[i]][y[i]]++;
  }
  for(int i = 1; i<=MM; i++){
    for(int j = 1; j<=MM; j++){
      psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }
  }
  for(int i = 0; i<n; i++){
    int btr = psa[MM][MM] - psa[x[i]][MM] - psa[MM][y[i]] + psa[x[i]][y[i]], wrs = psa[x[i]-1][y[i]-1];
    if(x[i] == MM) wrs += psa[1][y[i]] - psa[1][y[i]-1];
    if(y[i] == MM) wrs += psa[x[i]][1] - psa[x[i]-1][1];
    cout<<btr + 1<<" "<<(n-wrs)<<"\n";
  }
}