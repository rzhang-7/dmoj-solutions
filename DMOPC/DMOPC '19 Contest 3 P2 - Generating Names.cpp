#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc19c3p2

// easier with recursion (https://github.com/Ninjaclasher/Competitive-Programming/blob/master/DMOPC/dmopc19c3p2.cpp)

int n, k;
string str;
vector<int> v(26);

ll fct(int x){
  ll ans = 1;
  for(int i = 2; i<=x; i++)
    ans *= i;
  return ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  ll ans = 0;
  cin>>n>>k>>str;
  for(char c : str){
    if(c >= 'a')
      v[c - 'a']++;
  }
  if(k == 0){
    ll total = fct(n);
    for(int x : v)
      total /= fct(x);
    ans = total;
  }
  if(k == 1){
    for(int i = 0; i<26; i++){
      v[i]++;
      ll total = fct(n);
      for(int x : v)
        total /= fct(x);
      ans += total;
      v[i]--;
    }
  }
  if(k == 2){
    for(int i = 0; i<26; i++){
      v[i]++;
      for(int j = i; j<26; j++){
        v[j]++;
        ll total = fct(n);
        for(int x : v)
          total /= fct(x);
        ans += total;
        v[j]--;
      }
      v[i]--;
    }    
  }
  cout<<ans<<"\n";
}