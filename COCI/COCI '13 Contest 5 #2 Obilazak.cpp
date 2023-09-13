#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci13c5p2

int k, arr[1024];
vector<int> v[10];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>k;
  for(int i = 0; i<(1<<k)-1; i++){
    cin>>arr[i];
  }
  for(int i = 0; i<k; i++){
    for(int j = (1<<i)-1; j<(1<<k)-1; j+=(1<<(i+1)))
      v[i].push_back(arr[j]);
  }
  for(int i = k-1; i>=0; i--){
    for(int x : v[i])
      cout<<x<<" ";
    cout<<"\n";
  }
}

/*
         1
   2            3
 4    5      6     7
8 9 10 11  12 13 14 15

8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
*/