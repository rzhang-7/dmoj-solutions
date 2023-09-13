#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc07j2

map<string,string> t = {
  {"CU","see you"},
  {":-)","I'm happy"},
  {":-(","I'm unhappy"},
  {";-)","wink"},
  {":-P","stick out my tongue"},
  {"(~.~)","sleepy"},
  {"TA","totally awesome"},
  {"CCC","Canadian Computing Competition"},
  {"CUZ","because"},
  {"TY","thank-you"},
  {"YW","you're welcome"},
  {"TTYL","talk to you later"}
};
map<string,string>::iterator it;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  do {
    cin>>str;
    it = t.find(str);
    if(it != t.end())
      cout<<t.find(str)->second<<"\n";
    else cout<<str<<"\n"; 
  } while(str != "TTYL");
}