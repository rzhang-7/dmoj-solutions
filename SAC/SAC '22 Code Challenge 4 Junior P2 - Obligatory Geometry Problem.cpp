#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc4jp2

const int MM = 1e5+1;

int n, q;
string arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 0; i<q; i++){
    string type, shape;
    int idx;
    cin>>type>>shape>>idx;
    if(type == "set"){
      arr[idx] = shape;
    } else {
      cout<<(arr[idx] == shape ? 1 : 0)<<"\n";
    }
  }
}