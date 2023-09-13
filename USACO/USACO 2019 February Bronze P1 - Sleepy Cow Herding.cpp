#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/usaco19febb1

bool isCons(vector<int> arr){
  if(arr[2] == arr[1] + 1 && arr[1] == arr[0] + 1) return true; 
  return false;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int c, min = 0, max = 0;
  vector<int> field;
  for(int i = 0; i<3; i++){
    cin>>c;
    field.push_back(c);
  }
  sort(field.begin(), field.end());
  if(isCons(field)){ 
    cout<<"0\n0\n";
    return 0;
  }
  field[0] + 2 == field[1] || field[1] == field[2] - 2 ? min = 1 : min = 2;
    
  max = std::max(field[2] - field[1], field[1] - field[0]) - 1;
  cout<<min<<"\n"<<max<<"\n";
}