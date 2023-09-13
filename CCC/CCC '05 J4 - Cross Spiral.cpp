#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc05j4

int row, col, w, l, steps; char dir = 'R';
bool room[22][22];

// void printBoard(){
//   for(int i = 1; i<=row; i++){
//     for(int j = 1; j<=col; j++){
//       cout<<room[i][j]<<" ";
//     }
//     cout<<"\n";
//   }
//   cout<<"\n";
// }

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>col>>row>>w>>l>>steps;
  for(int i = 1; i<=l; i++){
    for(int j = 1; j<=w; j++){
      room[i][j] = true;
      room[i][col-j+1] = true;
      room[row-i+1][j] = true;
      room[row-i+1][col-j+1] = true;
    }
  }

  if(2*w == col-1) dir = 'D';
  int x = w+1, y = 1;
  for(int i = 1; i<=steps; i++){
    if(room[y][x+1] && room[y][x-1] && room[y+1][x] && room[y-1][x]){
      cout<<x<<"\n"<<y<<"\n";
      return 0;
    }
    
    room[y][x] = true;
    
    if(dir == 'R') {
      x++;
      if(room[y][x+1] || x+1 > col) dir = 'D';
      else if(room[y-1][x-1] && !room[y-1][x]) dir = 'U';
      
    } else if(dir == 'L') {
      x--;
      if(room[y][x-1] || x-1 <= 0) dir = 'U';
      else if(room[y+1][x+1] && !room[y+1][x]) dir = 'D';
      
    } else if(dir == 'D') {
      y++;
      if(room[y+1][x] || y+1 > row) dir = 'L';
      else if(room[y-1][x+1] && !room[y][x+1]) dir = 'R';
      
    } else if(dir == 'U') {
      y--;
      if(room[y-1][x] || y-1 <= 0) dir = 'R';
      else if(room[y+1][x-1] && !room[y][x-1]) dir = 'L';
    }
    // printBoard();
  }
  cout<<x<<"\n"<<y<<"\n";
}