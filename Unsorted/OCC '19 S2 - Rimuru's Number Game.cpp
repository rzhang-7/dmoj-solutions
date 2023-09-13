#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/occ19s2

ll n, ans;

void solve(string s){
  if(!s.empty()){
    if(stoll(s)<=n) ans++;
    else return;
  } 
  s.push_back('2');
  solve(s);
  s.pop_back();
  s.push_back('3');
  solve(s);
}

int main() {
  cin>>n;
  string s = "";
  solve(s);
  cout<<ans<<"\n";
}