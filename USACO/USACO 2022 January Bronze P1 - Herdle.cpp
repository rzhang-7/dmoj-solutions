#include <iostream>
using namespace std;

// https://dmoj.ca/problem/usaco22janb1

int n, guess_cnt[26], answer_cnt[26], green, yellow;
string guess[3], answer[3];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<3; i++){
    cin>>answer[i];
    for(int j = 0; j<3; j++){
      answer_cnt[answer[i][j] - 'A']++;
    }
  }
  for(int i = 0; i<3; i++){
    cin>>guess[i];
    for(int j = 0; j<3; j++){
      guess_cnt[guess[i][j] - 'A']++;
    }
  }
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      if(answer[i][j] == guess[i][j]){
        green++;
        guess_cnt[guess[i][j] - 'A']--;
        answer_cnt[answer[i][j] - 'A']--;
      }
    }
  }
  for(int i = 0; i<26; i++){
    yellow += min(answer_cnt[i], guess_cnt[i]);
  }
  cout<<green<<"\n"<<yellow<<"\n";
}

// guess[i][j] - 'A' converts a char to a number
// 'A' - 'A' = 0, 'B' - 'A' = 1, 'C' - 'A' = 2, etc.