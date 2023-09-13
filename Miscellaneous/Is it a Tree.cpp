#include <iostream>
using namespace std;

// https://dmoj.ca/problem/tree1

int edge; bool tree = true;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<4; i++){
    int sum = 0;
    for(int j = 0; j<4; j++){
      int n;
      cin>>n;
      sum += n;
    }
    if(sum == 0)
      tree = false; 
    edge += sum;
  }
  cout<<(edge != 6 || !tree ? "No" : "Yes")<<"\n";
}