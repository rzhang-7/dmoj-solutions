#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc19s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  int h = 0, v = 0;
  cin>>str;
  for(char c : str){
    c == 'H' ? h++ : v++;
  }
  if(h%2 == 1 && v%2 == 1){
    cout<<"4 3\n2 1\n";
  } else if(h%2 == 1 && v%2 == 0){
    cout<<"3 4\n1 2\n";
  } else if(h%2 == 0 && v%2 == 1){
    cout<<"2 1\n 4 3\n";
  } else {
    cout<<"1 2\n3 4\n";
  }
  cout<<h<<" "<<v<<"\n";
}