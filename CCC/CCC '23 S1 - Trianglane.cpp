#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc23s1

const int MM = 2e5+1;

int arr[2][MM], ans = 0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 0; i<2; i++){
    for(int j = 0; j<n; j++){
      cin>>arr[i][j]; 
    }
  }
  for(int i = 0; i<2; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j]){
        ans += 3;
      } 
    }
  }

  for(int i = 0; i<2; i++){
    for(int j = 1; j<n; j+=2){
      if(arr[i][j]){
        if(arr[i][j-1]) ans -= 2;
        if(arr[i][j+1]) ans -= 2;
      } 
    }
  }
  for(int i = 0; i<n; i+=2){
    if(arr[1][i] && arr[0][i]) ans -= 2;
  }

  cout<<ans<<"\n";
}