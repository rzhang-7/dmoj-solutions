#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// https://dmoj.ca/problem/crci08p2

int r, n, act, ans;
string sven;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>r>>sven;
  cin>>n;
  vector<unordered_map<char,int>> v(r);
  for(int i = 0; i<n; i++){
    for(int j = 0; j<r; j++){
      char c;
      cin>>c;
      v[j][c]++;
      switch(c){
        case 'R':
          switch(sven[j]){
            case 'R':
              act++;
              break;
            case 'P':
              act+=2;
              break;
          }
          break;  
        case 'P':
          switch(sven[j]){
            case 'P':
              act++;
              break;
            case 'S':
              act+=2;
              break;
          }
          break;
        case 'S':
          switch(sven[j]){
            case 'S':
              act++;
              break;
            case 'R':
              act+=2;
              break;
          }
          break;
      }
    }
  }
  cout<<act<<"\n";
  for(int i = 0; i<r; i++){
    int add = -1; char mv;
    for(auto x : v[i]){
      switch(x.first){
        case 'R':
          mv = 'P';
          break;
        case 'P':
          mv = 'S';
          break;
        case 'S':
          mv = 'R';
          break;
      }
      add = max(add, 2*x.second + v[i][mv]);
    }
    ans += add;
  }
  cout<<ans<<"\n";
}