#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/dmopc17c4p4

const int MM = 1e6+1;

int n; bool vis[MM], arr[MM];
deque<int> g, ng;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1,x; i<=n; i++){
    cin>>x;
    if(!vis[x]){
      vis[x] = true; arr[i] = true;
      g.push_back(x);
    }
  }
  for(int i = 1; i<=n; i++){
    if(!vis[i]) ng.push_back(i);
  }
  if(g.size() == 1){
    cout<<-1<<"\n";
    return 0;
  }
  g.push_back(g.front());
  g.pop_front();
  for(int i = 1; i<=n; i++){
    if(arr[i]){
      cout<<g.front()<<" "; g.pop_front();
    } else {
      cout<<ng.front()<<" "; ng.pop_front();
    }
  }
  cout<<"\n";
}