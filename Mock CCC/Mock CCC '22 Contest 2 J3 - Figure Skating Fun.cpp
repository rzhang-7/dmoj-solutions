#include <iostream>
using namespace std;

// https://dmoj.ca/problem/mccc4j3

const int MM = 1e6+1;

int n, arr[MM], sum = 0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=n; i++){
    sum += arr[i];
  }
  if(sum%2){
    cout<<"Andrew is sad.\n";
    return 0;
  }
  for(int i = 1, s = 0; i<=n; i++){
    s += arr[i];
    if(s == sum/2){ 
      cout<<i<<"\n";
      return 0;
    }
  }
  cout<<"Andrew is sad.\n";
}