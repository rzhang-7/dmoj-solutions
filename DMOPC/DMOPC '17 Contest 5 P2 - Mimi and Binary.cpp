#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc17c5p2

vector<int> a(1), b(1);

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s;
  int q, c0 = 0, c1 = 0;
  cin>>s>>q;
  for(char c : s){
    c0 += c=='0';
    c1 += c=='1';
    a.push_back(c0);
    b.push_back(c1);
  }
  for(int i = 0, x, y, z; i<q; i++){
    cin>>x>>y>>z;
    int ans = (z ? lower_bound(b.begin(), b.end(), y + b[x-1]) - b.begin() : lower_bound(a.begin(), a.end(), y + a[x-1]) - a.begin());
    
    cout<<(ans > (int)s.size() ? -1 : ans)<<"\n";
  }
}