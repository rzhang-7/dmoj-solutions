#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc17c5p1

string s;
vector<pair<char,char>> v = {{'0','O'},{'1','l'},{'3','E'},{'4','A'},{'5','S'},{'6','G'},{'8','B'},{'9','g'}};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  for(char c : s){
    int a = -1;
    for(auto x : v){
      if(x.first == c){
        a = x.second;
        break;
      }
      // else if(x.second == c){
      //   a = x.first;
      //   break;
      // }
    }
    cout<<(a == -1 ? c : (char)a);
  }
  cout<<"\n";
}