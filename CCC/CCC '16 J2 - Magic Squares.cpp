#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/ccc16j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, arr[4][4];
  unordered_set<int> check;
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      cin>>n;
      arr[i][j] = n;
    }
  }

  for(int i = 0; i<4; i++){
    int sumR = 0, sumC = 0;
    for(int j = 0; j<4; j++){
      sumR += arr[i][j];
      sumC += arr[j][i];
    }
    check.insert(sumR);
    check.insert(sumC);
  }
  if(check.size() == 1) cout<<"magic\n";
  else cout<<"not magic\n";
}