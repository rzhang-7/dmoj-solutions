#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc3jp1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  cout<<(s.find("demello")==-1?"what are we going to do?":"liar")<<"\n";
}