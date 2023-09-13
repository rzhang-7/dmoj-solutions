#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ics4p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin>>str;
  sort(str.begin(), str.end());
  do{
    for(char c : str){
      cout<<c;
    }
    cout<<"\n";
  } while(next_permutation(str.begin(), str.end()));
}