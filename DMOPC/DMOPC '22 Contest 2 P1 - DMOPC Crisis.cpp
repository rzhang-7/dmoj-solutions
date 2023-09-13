#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc22c2p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int periods = n/4, rem = n%4;
  int ans = 2 * periods;
  if(rem == 3) ans++;
  cout<<ans<<"\n";
  for(int i= 0; i<periods; i++){
    cout<<"MM__";
  }
  if(rem == 0) cout<<"\n";
  if(rem == 1) cout<<"_\n";
  if(rem == 2) cout<<"__\n";
  if(rem == 3) cout<<"M__\n";
  
  // MM_
  // MM__
  // MM___ 
  // MM____
  // MM__M__ 
  // MM__MM_
}