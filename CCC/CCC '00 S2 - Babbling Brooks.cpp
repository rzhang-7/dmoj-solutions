#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc00s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<double> v;
  for(int i = 1; i <= n; i++){
    int j;
    cin>>j;
    v.push_back(j);
  }
  while(true){
    int op;
    cin>>op;
    if(op == 77) break;
    if(op == 99) {
      int id, pct;
      cin>>id>>pct;
      id--;
      double lft = v[id] * pct / 100.0, rit = v[id] - lft;
      v[id] = lft;
      v.insert(v.begin()+id+1, rit);
    }
    else{
      int id;
      cin>>id;
      id--;
      v[id] = v[id] + v[id+1];
      v.erase(v.begin()+id+1);
    }
  }
  for(unsigned i = 0; i<v.size(); i++){
    double round(v[i]);
    cout<<round<<" ";
  }
  cout<<"\n";
}
