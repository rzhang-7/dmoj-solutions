#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc15j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, f, time = 0;
  char com;
  map<int,int> text, send, rs;
  cin>>n;
  while(n--){
    cin>>com>>f;
    if(com == 'R'){
      text[f] = time;
      rs[f]++;
      time++;
    }
    else if(com == 'W'){
      time += f - 1;
    }
    else if(com == 'S'){
      send[f] += time - text[f];
      rs[f]--;
      time++;
    }
  }
  for(auto r: rs){
    if(r.second > 0) send[r.first] = -1;
  }
  for(auto x: send){
    cout<<x.first<<" "<<x.second<<"\n";
  }
}