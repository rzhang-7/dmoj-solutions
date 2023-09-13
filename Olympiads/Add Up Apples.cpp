#include <iostream>
using namespace std;

// https://dmoj.ca/problem/apples

int n, cnt = 0;

void fun(int last, int sum, string sol){
  if(sum == n){
    cout<<sol<<"\n";
    cnt++;
    return;
  }
  for(int cur = last; cur + sum <= n; cur++){
    fun(cur, sum+cur, sol + "+" + to_string(cur));
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n/2; i++){
    fun(i, i, to_string(n) + "=" + to_string(i));
  }
  cout<<"total="<<cnt<<"\n";
}