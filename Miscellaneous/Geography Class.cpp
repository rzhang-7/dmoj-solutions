#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/geography

const int MM = 1e5+1;

int n; ll sieve[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<MM; i++){
    for(int j = i; j<MM; j+=i){
      sieve[j] += (ll)pow(i,2);
    }
  }
  for(int i=0,x; i<n; i++){
    cin>>x;
    cout<<sieve[x]<<"\n";
  }
}