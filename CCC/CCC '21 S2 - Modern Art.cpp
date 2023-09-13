#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc21s2

int m, n, k, ans = 0;
int row[5000000], col[5000000];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>m>>n>>k;
  for(int i = 0; i<k; i++){
    char c;
    int num;
    cin>>c>>num;
    if(c == 'R'){
      row[num-1]++;
    } else {
      col[num-1]++;
    }
  }
  for(int i = 0; i<m; i++){  
    for(int j = 0; j<n; j++){
      if((row[i] + col[j]) % 2) ans++;
    }
  }
  cout<<ans<<"\n";
}