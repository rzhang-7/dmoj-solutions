#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/year2017p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  char qry;
  deque<int> list;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>qry>>x;
    if(qry == 'F') list.push_front(x);
    else if(qry == 'E') list.push_back(x);
    else if(qry == 'R'){
      deque<int>::iterator it = list.begin();
      while(it != list.end()){
        if(*it == x){
          list.erase(it);
          break;
        }
        it++;
      }
    }
  }
  for(auto i : list){
    cout<<i<<"\n";
  }
}