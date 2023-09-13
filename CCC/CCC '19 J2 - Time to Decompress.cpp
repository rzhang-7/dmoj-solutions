#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc19j2

int n, l;
char c;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    cin>>l>>c;
    cout<<string(l,c)<<"\n";
  }
}