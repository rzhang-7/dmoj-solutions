#include <iostream>
using namespace std;

// dmoj.ca/problem/ccc00s1

int n,a,b,c, play = 0;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>a>>b>>c;
  while(n > 0){
    if(--n >= 0){
      a++;
      if(a % 35 == 0){
        n += 30;
      }
      play++;
    }
    if(--n >= 0){
      b++;
      if(b%100 == 0){
        n+=60;
      }
      play++;
    }
    if(--n >= 0){
      c++;
      if(c%10 == 0){
        n+=9;
      }
      play++;
    }
  }
  cout<<"Martha plays "<<play<<" times before going broke."<<"\n";
}
