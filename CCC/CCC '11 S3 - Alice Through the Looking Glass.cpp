#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/ccc11s3

int n, blk[5][5];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  blk[1][0] = blk[2][0] = blk[3][0] = blk[2][1] = 1; // always crystal
  blk[1][1] = blk[2][2] = blk[3][1] = -1; // unsure, need to zoom in
  for(int i = 0, m, x, y; i<n; i++){
    cin>>m>>x>>y;
    while(m > 0){
      int blkSize = pow(5, m-1), bx = x/blkSize, by = y/blkSize;
      if(blk[bx][by] == 1){
        cout<<"crystal\n";
        break;
      }
      else if(blk[bx][by] == 0){
        cout<<"empty\n";
        break;
      }
      else {
        if(m == 1) {
          cout<<"empty\n";
          break;
        }
        // zoom in (recursion)
        m--;
        x = x % blkSize; y = y % blkSize;
      }
    }    
  }
}