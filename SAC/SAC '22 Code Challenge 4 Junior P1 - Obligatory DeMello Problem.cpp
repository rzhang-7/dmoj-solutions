#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc4jp1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s, vowel = "aeiouy";
  int cnt = 0;
  cin>>s;
  for(char c : s){
    if((int)vowel.find(c) != -1) cnt++;
  }
  cout<<(cnt>=2?"good":"bad")<<"\n";
}