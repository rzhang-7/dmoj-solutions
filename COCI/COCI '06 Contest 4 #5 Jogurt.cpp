#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci06c4p5

vector<pair<int,int>> tree;

int f(vector<int> &p){
  if(p.size() == 3){
    tree[p[0]].first = p[2];
    tree[p[0]].second = p[1];
    return p[0];
  }
  int m = p.size()/2 - 1, root = p[m];
  vector<int> r, l;
  for(int i = 0; i<m; i+=2){
    l.push_back(p[i]);
    r.push_back(p[i+1]);
  }
  for(int i = m+1; i<(int)p.size(); i+=2){
    r.push_back(p[i]);
    l.push_back(p[i+1]);    
  }
  tree[root].first = f(l); tree[root].second = f(r);
  return root;
}

void dfs(int root){
  if(root == 0) return;
  cout<<root<<" ";
  dfs(tree[root].first);
  dfs(tree[root].second);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  if(n == 1) {cout<<1<<"\n"; return 0;}
  int lmt = (1<<n)-1; 
  tree.resize(lmt+1);
  vector<int> p;
  for(int i = 1; i<=lmt; i++){
    p.push_back(i);
  }
  tree[0].first = f(p);
  dfs(tree[0].first);
  cout<<"\n";
}