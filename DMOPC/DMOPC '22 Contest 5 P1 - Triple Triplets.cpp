#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc22c5p1

ll n, ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(ll i = 1; i <= n/2-1; i++){
    ll bc = (n-i*2-1) * (n-i*2) / 2;
    ans = max(ans, bc*i);
  }
  cout<<ans<<"\n";
}

// Idea:
// imagine an array of size n-1 with all values being 1 except at index n-1, where the value is 2
// for instance, with n = 5 the array is [1,1,1,2]
// thus the triplets are (1,2,4), (1,3,4) and (2,3,4), all evaluating to 1 + 1 = 2
// 1 1 1 2    n

// Actual solution:
// same as the idea, but the answer may not be an array with only one 2.
// the formula for the number of triples is the binomial coefficient of the number of 1s and 2, multiplied by the number of 1s
// thus the answer is calculated by going through all the numbers of 2 in the array