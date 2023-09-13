#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc21c7p1

const ll MM = 1502;

ll n, m, arr[MM][MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      if(arr[i][j] == 0){
        arr[i][j] = max(arr[i-1][j], arr[i][j-1]) + 1;
      }
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      if((arr[i][j] >= arr[i][j+1] && arr[i][j+1]) || (arr[i][j] >= arr[i+1][j] && arr[i+1][j])){
        cout<<-1<<"\n"; return 0;
      }
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      cout<<arr[i][j]<<(j == m ? "\n"  : " ");
    }
  }
}