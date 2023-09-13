#include <iostream>
using namespace std;

// https://dmoj.ca/problem/gfssoc2j5

const int MM = 5e5+3;

int n, q, arr[MM], pmx[MM], pc[MM], smx[MM], sc[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
    if(pmx[i-1] < arr[i]){
      pmx[i] = arr[i];
      pc[i] = 1;
    } else if(pmx[i-1] == arr[i]) {
      pmx[i] = pmx[i-1];
      pc[i] = pc[i-1]+1;
    } else {
      pmx[i] = pmx[i-1];
      pc[i] = pc[i-1];
    }
  }
  for(int i = n; i >= 1; i--){
    if(smx[i+1] < arr[i]){
      smx[i] = arr[i];
      sc[i] = 1;
    } else if(smx[i+1] == arr[i]) {
      smx[i] = smx[i+1];
      sc[i] = sc[i+1]+1;
    } else {
      smx[i] = smx[i+1];
      sc[i] = sc[i+1];
    }
  }
  for(int i = 1, l, r; i<=q; i++){
    cin>>l>>r;
    if(pmx[l-1] > smx[r+1]){
      cout<<pmx[l-1]<<" "<<pc[l-1]<<"\n";
    } else if(pmx[l-1] == smx[r+1]) {
      cout<<pmx[l-1]<<" "<<pc[l-1] + sc[r+1]<<"\n";
    } else {
      cout<<smx[r+1]<<" "<<sc[r+1]<<"\n";
    }
  }
}