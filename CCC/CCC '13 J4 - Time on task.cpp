#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc13j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t, c, ans = 0, comp = 0;
  cin>>t>>c;
  int arr[c];
  for(int i = 0; i<c; i++){
    cin>>arr[i];
  }
  sort(arr, arr + c);
  for(int i = 0; i < c; i++){
    if(arr[i] + comp <= t){
      ans++;
      comp += arr[i];
    }
    else if(arr[i] + comp > t) break;
  }
  cout<<ans<<"\n";
}