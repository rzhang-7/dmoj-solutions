#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/p183ex6

/**** Combinations for Pascal's Triangle ****

nCr = (n) = n!/r!(n-r)!
      (r)
nCr+1 = n!/(r+1)!(n-r-1)! 
      = n!(n-r)/(r+1)r!(n-r)!
      = n-r/r+1 nCr

n = 0      0C0
n = 1    1C0 1C1
n = 2  2C0 2C1 2C2

********************************************/

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;

  for(int i = 1; i <= n; i++){
    int val = 1;
    for(int j = 1; j <= i; j++){
      cout<<val<<" ";
      val = val * (i-j)/j;
    }
    cout<<"\n";
  }
}

// Alternate solution using 2D arrays
// int n;
// cin>>n;
// arr[n+1][n+1];
// arr[1][1] = 1;
// for(int i = 2; i<=n; i++){
//   for(int j = 1; j<=i; j++){
//     a[i][j] = a[i-j][j] + a[i-1][j-1];
//   }
// }
// for(int i = 1; i<=n; i++){
//   for(int j = 1; j<=n; j++){
//     cout<<a[i][j]<<" ";
//   }
//   cout<<"\n";
// }