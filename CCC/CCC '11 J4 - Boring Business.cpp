#include <iostream>
#include <set>
using namespace std;

// https://dmoj.ca/problem/ccc11j4

set<pair<int,int>> route = {{0,-1},{0,-2},{0,-3},{1,-3},{2,-3},{3,-3},{3,-4},{3,-5},{4,-5},{5,-5},{5,-4},{5,-3},{6,-3},{7,-3},{7,-4},{7,-5},{7,-6},{7,-7},{6,-7},{5,-7},{4,-7},{3,-7},{2,-7},{1,-7},{0,-7},{-1,-7},{-1,-6},{-1,-5}};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int x = -1, y = -5, len;
  char dir;
  bool safe = true;
  for(cin>>dir>>len; dir != 'q'; cin>>dir>>len){
    int a = x, b = y;
    if(dir == 'r'){
      x += len;
      for(int i = a+1; i<=x; i++){
        if(route.count(make_pair(i,y)) != 0) safe = false;
        route.insert(make_pair(i,y));
      }
    } else if(dir == 'l'){
      x -= len;
      for(int i = x; i<a; i++){
        if(route.count(make_pair(i,y)) != 0) safe = false;
        route.insert(make_pair(i,y));
      }
    } else if(dir == 'u'){
      y += len;
      for(int i = b+1; i<=y; i++){
        if(route.count(make_pair(x,i)) != 0) safe = false;
        route.insert(make_pair(x,i));
      }      
    } else {
      y -= len;
      for(int i = y; i<b; i++){
        if(route.count(make_pair(x,i)) != 0) safe = false;
        route.insert(make_pair(x,i));
      }
    }
    if(safe){
      cout<<x<<" "<<y<<" safe\n";      
    } else {
      cout<<x<<" "<<y<<" DANGER\n";
      return 0;
    }
  }
}