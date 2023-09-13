#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/coci07c4p2

int x, ans = INT32_MAX;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>x;
  vector<int> v;
  for(int i = x; i!=0; i/=10){
    v.push_back(i%10);
  }
  sort(v.begin(), v.end());
  do{
    int num = 0;
    for(int i = 0; i<(int)v.size(); i++){
      num += v[i] * pow(10,i);
    }
    if(num > x){
      ans = min(num, ans);
    }
  } while(next_permutation(v.begin(), v.end()));
  
  cout<<(ans == INT32_MAX ? 0 : ans)<<"\n";
}


// much simpler way
// string x;
// cin >> x;
// if(next_permutation(x.begin(), x.end())){
//   cout << x << "\n";
// } else {
//   cout << 0 << "\n";
// }