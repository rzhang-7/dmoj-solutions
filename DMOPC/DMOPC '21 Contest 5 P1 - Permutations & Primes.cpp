#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc21c5p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; vector<int> v;
  cin>>n;
  if(n == 1){
    cout<<1<<"\n";
  } else if(n <= 4){
    cout<<-1<<"\n";
  } else {
    for(int i = 2; i<=n; i+=2){
      v.push_back(i);
    }
    for(int i = 1; i<=n; i+=2){
      for(int j = 2; j*j<=i+n-n%2; j++){
        if((i+n-n%2)%j == 0){
          for(int x : v) cout<<x<<" ";
          cout<<i<<" ";
          for(int x = 1; x<=n; x+=2){
            if(x != i) cout<<x<<" \n"[x==n||x==n-1||i==n&&x==n-2];
          }
          return 0;
        }
      }
    }
    cout<<-1<<"\n";
  }
}