#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc18c6p0

int a,b,c,cnt;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>c;
  if(a) cnt++;
  if(b) cnt++;
  if(c) cnt++;
  if(cnt < 2) cout<<"YES\n";
  else if(cnt == 3) cout<<"NO\n";
  else{
    if(!a){
      cout<<(b+2==c+3 ? "NO\n":"YES\n");
    }
    if(!b){
      cout<<(a+1==c+3? "NO\n":"YES\n");
    }
    if(!c){
      cout<<(a+1==b+2 ? "NO\n":"YES\n");
    }   
  }
}  