#include <iostream>
using namespace std;

// https://dmoj.ca/problem/coci14c5p3

const int MM = 1e5;

int n, k, row[MM], col[MM], rightD[2*MM-1], leftD[2*MM-1];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 1, x,y; i<=n; i++){
    cin>>x>>y; 
    x--; y--;
    row[x]++;
    col[y]++;
    leftD[x+MM-1-y]++;
    rightD[x+y]++;
    if(row[x] == k || col[y] == k || rightD[x+y] == k || leftD[x+MM-1-y] == k){
      cout<<i<<"\n"; return 0;
    }
  }
  cout<<-1<<"\n";
}