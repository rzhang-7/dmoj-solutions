#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/sac21ccp3

int n, p;
pair<string,ll> mx = {"", -1}, mn = {"", INT64_MAX};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>p;
  for(int i = 1; i<=n; i++){
    ll m, cs, e;
    string s;
    cin>>s>>m>>cs>>e;
    ll score = floor(4*sqrt(m) + 3*(ll)pow(cs,p) - 4*e);
    if(mx.second < score){
      mx.second = score;
      mx.first = s;
    }
    else if(mn.second > score){
      mn.second = score;
      mn.first = s;
    }
  }
  cout<<mx.first<<" "<<mx.second<<"\n";
  cout<<mn.first<<" "<<mn.second<<"\n";
}