#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

// https://dmoj.ca/problem/dmopc16c4p3

const int MM = 1e5+1;

ll n, s, q, arr[MM];
set<pair<ll,ll>> candy[101];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);        
  cin>>n>>s;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1, x, k; i<=s; i++){
    cin>>x>>k;
    candy[k].insert({arr[x],x});
  }
  cin>>q;
  for(int i = 1, x, k; i<=q; i++){
    char op;
    cin>>op>>x;
    switch(op){
      case 'A':
        cin>>k;
        candy[k].insert({arr[x],x});
        break;
      case 'S':
        cin>>k;
        if(!candy[k].empty()) candy[k].erase({arr[x],x});
        break;
      case 'E':
        cin>>k;
        for(int j = 0; j<=100; j++){
          if(!candy[j].empty()) candy[j].erase({arr[x],x});
        }
        arr[x] = k;
        break;
      case 'Q':
        if(candy[x].empty()){
          cout<<"-1\n";
          break;
        }
        auto ans = candy[x].begin();
        cout<<candy[x].begin()->second<<"\n";
        break;
    }
  }
}