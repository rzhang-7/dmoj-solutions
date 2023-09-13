#include <iostream>
using namespace std;

// https://dmoj.ca/problem/oly20practice74

int n, ans, idx, arr[5001];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  for(int i = 0; i<n; i++){
    int p = 0, tmp = arr[i];
    while(tmp%2==0){
      p = max(p,2);
      tmp/=2;
    }
    for(int j = 3; j<=tmp; j+=2){
      while(tmp%j==0){
        p = max(p, j);
        tmp/=j;
      }
    }
    if(tmp > 1) p = max(p, tmp);
    if(p>ans){
      ans = p;
      idx = i;
    }
  }
  cout<<arr[idx]<<"\n";
}