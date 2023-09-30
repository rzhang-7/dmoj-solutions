#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

// https://dmoj.ca/problem/dmopc18c4p4

const int MM = 2e5+1;

struct qry {
  int l, r, k, id;
} q[MM];

ll N, Q, bit[MM], ans[MM];
pi arr[MM];

void update(int i, ll val){
  for(; i < MM; i+=i&-i) bit[i] += val;
}

ll sum(int i){
  ll sum = 0; 
  for(; i>0; i-=i&-i){
    sum += bit[i];
  }
  return sum;
}

bool cmp(qry x, qry y){
  return x.k < y.k;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>N>>Q;
  for(int i = 1; i<=N; i++){
    cin>>arr[i].first;
    update(i, arr[i].first);
    arr[i].second = i;
  }
  for(int i = 1; i<=Q; i++){
    cin>>q[i].l>>q[i].r>>q[i].k;
    q[i].id = i;
  }
  sort(arr+1, arr+N+1);
  sort(q+1, q+Q+1, cmp);
  int mx = 1;
  for(int i = 1; i<=Q; i++){
    while(mx <= N && arr[mx].first < q[i].k){
      update(arr[mx].second, -(ll)2*arr[mx].first);
      mx++;
    }
    ans[q[i].id] = sum(q[i].r) - sum(q[i].l-1);
  }
  for(int i = 1; i<=Q; i++){
    cout<<ans[i]<<"\n";
  }
}