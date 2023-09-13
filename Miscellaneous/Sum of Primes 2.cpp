#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/alexquiz2

const int MM = 1e5;

int q;
vector<int> sieve(MM, -1);

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  sieve[0] = sieve[1] = 0;
  for(int i = 2; i<=MM; i++){
    if(sieve[i]==-1){
      for(long long j = (long long)i*i; j<=MM; j+=i)
        sieve[j] = 0;
      sieve[i] = i;
    }
  }
  for(int i = 2; i<=MM; i++)
    sieve[i] += sieve[i-1];
  cin>>q;
  for(int i = 0, a, b; i<q; i++){
    cin>>a>>b;
    cout<<sieve[b] - sieve[a-1]<<"\n";
  }
}