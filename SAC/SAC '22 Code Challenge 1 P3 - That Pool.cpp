#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/problem/sac22cc1p3

int row, col, q;
char pool[102][102], temp[102][102];

void fun(){
  for(int i = row; i>=1; i--){
    for(int j = 1; j<=col; j++){
      if(pool[i][j] == 'X') pool[i][j] = '.';
      if(pool[i-1][j] == 'X') pool[i][j] = 'X';
    }
  }

  for(bool change = true; change;){
    change = false; memset(temp, 0, sizeof(temp));
    for(int i = 1; i<=row; i++){
      for(int j = 1; j<=col; j++){
        for(int k = j; k>=1 && pool[i][k] == 'W' && pool[i][k-1] == '.'; k--){
          swap(pool[i][k], pool[i][k-1]);
          change = true;
        }
      }
    }
    for(int i = 1; i<=row; i++){
      for(int j = 1; j<=col; j++){
        if(pool[i][j] == 'W' && pool[i+1][j] == '.'){
          pool[i][j] = '.'; temp[i+1][j] = 'W'; change = true;
        }  
      }
    }
    for(int i = 1; i<=row; i++){
      for(int j = 1; j<=col; j++){
        if(temp[i][j] == 'W'){
          pool[i][j] = 'W';
        }
      }
    }
  }
}

void print(){
  for(int i = 1; i<=row; i++){
    for(int j = 1; j<=col; j++){
      cout<<pool[i][j];
    }
    cout<<"\n";
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>row>>col;
  for(int i = 1; i<=row; i++){
    for(int j = 1; j<=col; j++){
      cin>>pool[i][j];
    }
  }
  cin>>q;
  for(int i = 1, x; i<=q; i++){
    cin>>x;
    if(x == 1){
      fun();
    }
    else {
      print();
    }
  }
}