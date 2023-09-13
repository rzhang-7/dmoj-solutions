#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/dmopc18c1p2

int n, k;
//vector<int> rem[100];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    if(x % k != i % k){
      cout<<"NO\n"; return 0;
    }
  }
  cout<<"YES\n";  
}

//   cin.sync_with_stdio(0);
//   cin.tie(0);
//   cin>>n>>k;
//   for(int i = 0, x; i<n; i++){
//     cin>>x;
//     rem[i%k].push_back(x);
//   }
//   for(int i = 0; i<k; i++){
//     sort(rem.begin(), rem.end());
//     for(int j = 0; j<(int)rem[i].size(); j++){
//       if(rem[j] != j*k + i + 1){
//         cout<<"NO\n"; return 0;
//       }
//     }
//   }
//   cout<<"YES\n";
// }