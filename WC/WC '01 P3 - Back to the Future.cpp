#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/wc01p3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  stack<int> bin;
  cin>>n;
  while(n--){
    int p = 0, ans = 0;
    cin>>d;
    for(int i = d; i > 0; i /= 2){
      i % 2 == 0 ? bin.push(0) : bin.push(1);
    }
    while(!bin.empty()){
      ans += bin.top() * pow(2,p);
      p++;
      bin.pop();
    }
    cout<<ans<<"\n";
  }
}