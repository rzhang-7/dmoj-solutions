#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc19c1p2

string base = "Good writing is good writing is good writing.";
string pre = "Good writing is good ", mid = " writing is good ", suf = " is good writing.";
ll len[31]; 
int q;

char f(int lvl, int idx){
  if(lvl == 0) return base[idx];
  if(idx < pre.size()) return pre[idx];
  idx -= pre.size();
  if(idx < len[lvl-1]) return f(lvl-1, idx);
  idx -= len[lvl-1];
  if(idx < mid.size()) return mid[idx];
  idx -= mid.size();
  if(idx < len[lvl-1]) return f(lvl-1, idx);
  return suf[idx - len[lvl-1]];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  len[0] = base.size();
  for(int i = 1; i<=30; i++){
    len[i] = pre.size() + len[i-1] + mid.size() + len[i-1] + suf.size();
  }
  cin>>q;
  for(int i = 1, n, k; i<=q; i++){
    cin>>n>>k;
    cout<<(k > len[n] ? '.' : f(n, k-1))<<"\n";
  }
}