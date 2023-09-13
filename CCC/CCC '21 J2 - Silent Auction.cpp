#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc21j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, max = 0; 
  string winner;
  cin>>n;
  for(int i = 0; i<n; i++){
    string name;
    int v;
    cin>>name>>v;
    if(v>max){
      max = v;
      winner = name;
    }
  }
  cout<<winner<<"\n";
}