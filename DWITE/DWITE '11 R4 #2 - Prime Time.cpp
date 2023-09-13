#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/dwite11c4p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<5; i++){
    map<int,int> m;
    int n; cin>>n;
    if(n<4){
      cout<<"2^1"<<(n==3?" * 3^1\n":"\n");
      continue;
    }
    for(int j = n; j>=2; j--){
      int temp = j;
      for(int k = 2; k*k<=temp; k++){
        while(temp%k==0){
          m[k]++;
          temp /= k;
        }
      }
      if(temp > 1) m[temp]++;
    }
    for(auto x = m.begin(); x != m.end(); x++){
      cout<<x->first<<"^"<<x->second<<(x==--m.end()?"\n":" * ");
    }
  }
}