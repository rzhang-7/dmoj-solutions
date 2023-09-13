#include <iostream>
using namespace std;

// https://dmoj.ca/problem/pacnw16c

const int MM = 1e6+1;

int n, k, r, cnt, ans; 
bool arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k>>r;
  for(int i = 0, x; i<k; i++){
    cin>>x;
    if(x <= r) cnt++;
    arr[x] = true;
  }
  int f = r, b = 1;
// front pointer and back pointer to track how many cameras are in the range of f and b inclusive
  
  // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  // 0 1 0 0 1 0 1 0 0  1  0  0  1  0  0

  // 4, 9, 14
  while(true){
    for(int i = f; cnt<2; i--){
      if(!arr[i]){
        arr[i] = true;
        cnt++; ans++;
      }
    }
    if(f >= n) break;
    if(arr[++f]) cnt++;
    if(arr[b++]) cnt--;
  }
  cout<<ans<<"\n";
  // for(int i = 1; i<=n; i++){
  //   cout<<arr[i]<<" \n"[i==n];
  // }
}