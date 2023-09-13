#include <iostream>
using namespace std;

// https://dmoj.ca/problem/mccc4j2

const int MM = 1e5+1;

int n, a, b, x[MM], y[MM], sum1 = 0, sum2 = 0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a>>b;
  for(int i = 1; i<=n; i++){
    cin>>x[i]>>y[i];
  }
  for(int i = 1; i<=n; i++){
    sum1 += (x[i] < a ? 1 : 2);
    sum2 += (y[i] < b ? 1 : 2);
  }
  if(sum1 == sum2) cout<<"Tie!\n";
  else cout<<(sum1 < sum2 ? "Andrew" : "Tommy")<<" wins!\n";
}