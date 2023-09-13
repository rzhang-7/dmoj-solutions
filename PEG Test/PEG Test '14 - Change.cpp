#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/avatarchange

int ans, rl[4], ta[6];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<4; i++){
    cin>>rl[i];
  }
  for(int i = 0; i<6; i++){
    cin>>ta[i];
  }
  sort(ta,ta+6);
  do{
    int cnt = 0, sum, temp = 0;
    for(int i = 0; i<4; i++){
      sum = 0;
      while(sum <= rl[i] && cnt < 6){
        sum += ta[cnt];
        cnt++;
      }
      if(sum > rl[i]) temp++;
    }
    ans = max(ans, temp);
  } while(next_permutation(ta, ta+6));
  cout<<ans<<"\n";
}