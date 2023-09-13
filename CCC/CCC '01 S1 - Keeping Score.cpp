#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc01s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int p = 0, t = 0;
  string str;

  cin>>str;
  int dIndex = str.find('D');
  int hIndex = str.find('H');
  int sIndex = str.find('S');
  vector<char> C(str.begin()+1, str.begin() + dIndex);  
  vector<char> D(str.begin()+dIndex+1, str.begin() + hIndex);
  vector<char> H(str.begin()+hIndex+1, str.begin() + sIndex);
  vector<char> S(str.begin()+sIndex+1, str.end());
  
  cout<<"Cards Dealt   Points\n"<<"Clubs ";
  if(C.size() < 3) p = p + 3 - C.size();
  for(auto c: C) {
    if(c == 'A') p+=4;
    else if(c == 'K') p+=3;
    else if(c == 'Q') p+=2;
    else if(c == 'J') p++;
    cout<<c<<" ";
  }
  cout<<p<<"\nDiamonds ";
  t += p;
  p = 0;
  if(D.size() < 3) p = p + 3 - D.size();
  for(auto c: D) {
    if(c == 'A') p+=4;
    else if(c == 'K') p+=3;
    else if(c == 'Q') p+=2;
    else if(c == 'J') p++;
    cout<<c<<" ";
  }
  cout<<p<<"\nHearts ";
  t += p;
  p = 0;
  if(H.size() < 3) p = p + 3 - H.size();
  for(auto c: H) {
    if(c == 'A') p+=4;
    else if(c == 'K') p+=3;
    else if(c == 'Q') p+=2;
    else if(c == 'J') p++;
    cout<<c<<" ";
  }
  cout<<p<<"\nSpades ";
  t += p;
  p = 0;
  if(S.size() < 3) p = p + 3 - S.size();
  for(auto c: S) {
    if(c == 'A') p+=4;
    else if(c == 'K') p+=3;
    else if(c == 'Q') p+=2;
    else if(c == 'J') p++;
    cout<<c<<" ";
  }
  t += p;
  cout<<p<<"\nTotal "<<t<<"\n";
}
