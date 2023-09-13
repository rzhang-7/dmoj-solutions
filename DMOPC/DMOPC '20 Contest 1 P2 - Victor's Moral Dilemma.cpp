#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/dmopc20c1p2

int n, d;
deque<int> trolley, psa;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>d;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    trolley.push_back(x);
  }
  psa.push_back(trolley[0]);
  for(int i = 1; i<n; i++){
    psa.push_back(psa[i-1] + trolley[i]);
  }
  for(int i = 0, k; i<d; i++){
    cin>>k;
    int f = psa[k-1], s = psa[(int)psa.size()-1] - f;
  
    // for(int x : psa) {
    //   cout<<x<<" ";
    // } cout<<"\n";
    // cout<<f<<" "<<s<<"\n";
    
    psa.clear();
    if(f >= s){
      for(int j = 0; j<k; j++){
        trolley.pop_front();
      }
      cout<<f<<"\n";
    } else {
      for(int j = (int)trolley.size()-k; j>0; j--){
        trolley.pop_back();
      }
      cout<<s<<"\n";
    }

    psa.push_back(trolley[0]);
    for(int i = 1; i<(int)trolley.size(); i++){
      psa.push_back(psa[i-1] + trolley[i]);
    }
  }
}