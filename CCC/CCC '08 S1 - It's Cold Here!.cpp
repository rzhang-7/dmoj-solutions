#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc08s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int temp;
  string c;
  map<int,string> tc;
  do{
    cin>>c>>temp;
    tc[temp] = c;
  } while(c != "Waterloo");

  cout<<tc.begin()->second<<"\n";
}