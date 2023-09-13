#include <iostream>
#include <vector>
#include <map>
#include <numeric> // accumulate() calculates the sum of a list
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/ecoo19r1p2

int r, t; string s;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<10; i++){
    vector<ll> f(26);
    map<char, string> m;
    
    cin>>r>>t>>s;
    
    for(int j = 0; j<r; j++){
      char c; string a;
      cin>>c>>a;
      m[c] = a;
    }
    for(char c : s) f[c-'A']++;
    char fst = s[0], lst = s.back();
    for(int j = 1; j<=t; j++){
      vector<ll> f2(26);
      fst = m[fst][0]; lst = m[lst].back();
      for(auto kv : m){
        for(char c : kv.second){
          f2[c-'A'] += f[kv.first-'A'];
        }
      }
      swap(f, f2);
    }
    cout<<fst<<lst<<" "<<accumulate(f.begin(), f.end(), 0LL)<<"\n";
  }
}