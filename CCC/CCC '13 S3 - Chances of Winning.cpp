#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc13s3

int t, g, pt[5], ans;
bool done[5][5];
vector<pair<int,int>> game;

void fun(int id){
  if(id == (int)game.size()){
    bool flag = true;
    for(int i = 1; i<=4; i++){
      if(i != t && pt[i] >= pt[t]) flag = false;
    }
    if(flag) ans++;
    return;
  }
  int a = game[id].first, b = game[id].second;
  pt[a] += 3; fun(id+1); pt[a] -= 3;
  pt[b] += 3; fun(id+1); pt[b] -= 3;
  pt[a]++; pt[b]++; fun(id+1); pt[a]--; pt[b]--;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t>>g;
  for(int i = 1,a,b,sa,sb; i<=g; i++){
    cin>>a>>b>>sa>>sb; 
    done[a][b] = 1;
    if(sa>sb) pt[a] += 3;
    if(sb>sa) pt[b] += 3;
    if(sa==sb){pt[a]++; pt[b]++;}
  }
  for(int i = 1; i<=4; i++){
    for(int j = i+1; j<=4; j++){
      if(!done[i][j]) game.push_back({i,j});
    }
  }
  fun(0);
  cout<<ans<<"\n";
}