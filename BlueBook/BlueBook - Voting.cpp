#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p184ex8

int n, vote[7];
char c;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    cin>>c;
    vote[((c-'A'>5) || (c-'A'<0)? 6 : c-'A')]++;
  }
  for(int i = 0; i<7; i++){
    cout<<vote[i]<<"\n";
  }
}