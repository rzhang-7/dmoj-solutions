#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc14j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int l;
  int a = 0, b = 0;
  string votes;
  cin>>l>>votes;
  for(int i = 0; i<l; i++){
    if(votes[i] == 'A') a++;
    else if(votes[i]=='B') b++;
  }
  if(a>b) cout<<"A"<<"\n";
  else if(b>a) cout<<"B"<<"\n";
  else cout<<"Tie"<<"\n";  
}