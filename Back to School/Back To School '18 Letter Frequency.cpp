#include <iostream>
using namespace std;

// https://dmoj.ca/problem/bts18p2

int psa[26][1000001];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int q;
  string s;
  char c;
  getline(cin, s);
  
  for(int i = 1; i<=(int)s.length(); i++){
    for(int j = 0; j<26; j++){
      psa[j][i] = psa[j][i-1];
    }
    if(s[i-1] != ' '){
      psa[s[i-1] - 'a'][i]++;
    }
  }
  cin>>q;
  for(int i = 1, l, r; i<=q; i++){
    cin>>l>>r>>c;

    // using frequent range query (psa[r] - psa[l-1])
    // subtracting 'a' converts the character into a number from 0 - 25
    cout<<psa[c-'a'][r] - psa[c-'a'][l-1]<<"\n";
  }
}