#include <iostream>
using namespace std;

// https://dmoj.ca/problem/wc18c2s2

const int MM = 2e5+1;

int n, mi, mx, arr[MM];
bool o;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  int num = 0;
  if(arr[1] > 1){
    cout<<"-1\n"; return 0;
  } else {
    arr[1] = 1;
  }
  for(int i = n; i>=1; i--){
    if(arr[i] == 0 && !o) continue;
    if(!o){
      o = 1;
      num = arr[i]-1;
    } else {
      if(arr[i] && arr[i] != num){
        cout<<"-1\n"; return 0;
      }
      arr[i] = num--;
    }
    if(o && num == 0) o = 0;
  }
  for(int i = 1; i<=n; i++){
    mi += arr[i]==1;
    mx += arr[i]<=1;
  }
  cout<<mi-1<<" "<<mx-1<<"\n";
}