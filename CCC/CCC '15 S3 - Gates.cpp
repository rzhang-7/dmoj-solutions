#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc15s3

int g, p, ans; bool full;
vector<int> gates;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>g>>p;
  for(int i = 1; i<=g; i++){
    gates.push_back(i);
  }
  for(int i = 0, x; i<p; i++){
    cin>>x;
    int lo = 0, hi = gates.size()-1, id = -1;
    // Binary search
    while(lo<=hi && !full){
      int mid = (lo+hi)/2;
      if(gates[mid] == x){
        id = mid;
        break;
      }
      else if(gates[mid] < x){
        id = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    if(id != -1){
      ans++;
      gates.erase(gates.begin()+id);
    }
    else full = true;
    // for(int x : gates){
    //   cout<<x<<" ";
    // }cout<<"\n";
  }
  cout<<ans<<"\n";
}