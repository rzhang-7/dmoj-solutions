#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ecoo13r1p1

int n, t, line;
string op;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(cin>>op; op != "EOF"; cin>>op){
    if(op == "TAKE"){
      n++;
      t++;
      line++;
      if(n > 999) n = 1;
    } else if(op == "SERVE") {
      line--;
    } else if(op == "CLOSE") {
      cout<<t<<" "<<line<<" "<<n<<"\n";
      t = 0; line = 0;
    }
  }
}