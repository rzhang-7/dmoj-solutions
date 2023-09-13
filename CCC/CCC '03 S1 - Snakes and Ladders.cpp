#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc03s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int move;
  int board = 1;
  cin>>move;
  while(move != 0){
    if((board + move) > 100){
      cout<<"You are now on square "<<board<<"\n";
      cin>>move;
      continue;
    }
    
    board += move;
    
    if(board == 54) board = 19;
    else if(board == 90) board = 48;
    else if(board == 99) board = 77;
    else if(board == 9) board = 34;
    else if(board == 40) board = 64;
    else if(board == 67) board = 86;
    else if(board == 100){
      cout<<"You are now on square 100\nYou Win!"<<"\n";
      return 0;
    }
    cout<<"You are now on square "<<board<<"\n";
    cin>>move;
  }
  cout<<"You Quit!"<<"\n";
}