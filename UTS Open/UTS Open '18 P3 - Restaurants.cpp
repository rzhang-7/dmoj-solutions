#include <iostream>
using namespace std;
const int MM = 1e6+1;

// https://dmoj.ca/problem/utso18p3

// Very similar to https://dmoj.ca/problem/pacnw16c

int n, t, k, v, cnt, ans; 
bool arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t>>k>>v;
  for(int i = 0, x; i<v; i++){
    cin>>x;
    if(x <= t) cnt++;
    arr[x] = true;
  }
  int f = t, b = 1;
  while(true){
    for(int i = f; cnt<k; i--){
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