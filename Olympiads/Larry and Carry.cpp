#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/oly11c2b3

int N, arr[21], ans = 1;

bool check(vector<int> v){
  for(int i = 0; i<9; i++){
    int sum = 0;
    for(int x : v){
      sum += (x/(int)pow(10,i))%10;
    }
    if(sum >= 10) return false;
  }
  return true;
}

void getComb(int i, int n, vector<int>& comb){
  if(i>n){
    if(comb.empty()) return;
    if((int)comb.size()>ans){
      vector<int> vi;
      for(int x : comb){
        vi.push_back(arr[x]);
      }   
      if(check(vi)){
        ans = max(ans, (int)comb.size());
        // for(int x : vi) cout<<x<<" ";
        // cout<<"\n";
      }
    }
    return;
  }
  getComb(i+1, n, comb); 
  comb.push_back(i);
  getComb(i+1, n, comb);
  comb.pop_back();
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  vector<int> comb;
  cin>>N;
  for(int i = 1; i<=N; i++){
    cin>>arr[i];
  }
  getComb(1, N, comb);
  cout<<ans<<"\n";
}