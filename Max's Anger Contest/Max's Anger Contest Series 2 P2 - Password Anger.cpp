#include <iostream>
using namespace std;

// https://dmoj.ca/problem/macs2p2

// solvable with recursion (probably much cleaner)
// fun(1, "");
// void fun(int lvl, string s){
//     if(lvl > n) { cnt += get_hash(s) == m; return;}
//     for(char c = 'a'; c<='z'; c++)
//         fun(lvl+1, s+c);
// }

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m, ans = 0; cin>>n>>m;
  for(int i = 1; i<=26; i++){
    if(n == 1){
      ans += i == m;
      continue;
    }
    for(int j = 1; j<=26; j++){
      if(n == 2){
        ans += 13*i + j == m;
        continue;
      }  
      for(int k = 1; k<=26; k++){
        if(n == 3){
          ans += 169*i + 13*j + k == m;
          continue;
        } 
        for(int l = 1; l<=26; l++){
          if(2197*i + 169*j + 13*k + l == m){
            ans++;
          }
        }
      }
    }
  }
  cout<<ans<<"\n";
}