#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/sort1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int> v(n+2);
  for(int i = 1; i<=n; i++){
    cin>>v[i];
  }
  for(int i = 1; i<=n; i++)
    cout<<v[i]<<" \n"[i==n];
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<n; j++){
      if(v[j-1] > v[j] || v[j+1] < v[j]){
        int tmp = v[j];
        v[j] = v[j+1];
        v[j+1] = tmp;
        for(int k = 1; k<=n; k++){
          cout<<v[k]<<" \n"[k==n];
        }
      }
    }
  }
}