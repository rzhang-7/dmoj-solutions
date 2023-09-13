#include <iostream>
#include <cstring>
using namespace std;

// https://dmoj.ca/problem/bf4
// cheesed with strstr(), might include solution with string hash

const int MM = 1e6+1;

int main() {
  char s[MM], t[MM];
  cin>>s>>t;
  char *ans = strstr(s, t);
  cout<<(ans==NULL?-1:ans-s)<<"\n";
}