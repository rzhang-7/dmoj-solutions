#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc4p2

int dist(char a, char b){
  return min(abs(a-b), 26 - abs(a-b));
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int K;
  string C;
  cin>>K>>C;
  for(char i = 'a'; i<='z'; i++){
    for(char j = 'a'; j<='z'; j++){
      for(char k = 'a'; k<='z'; k++){
        for(char l = 'a'; l<='z'; l++){
          if(dist(i, C[0]) + dist(j, C[1]) + dist(k, C[2]) + dist(l, C[3]) <= K){
            cout<<i<<j<<k<<l<<"\n";
          }
        }
      }
    }
  }
}