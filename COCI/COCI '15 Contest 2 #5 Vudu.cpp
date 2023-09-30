#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/coci15c2p5

// given an array A, find the number of subarrays with an average >= P
// subtract all values of A by P, then put into a psa
// get the answer by doing inversion counting on the psa
// do coordinate compression with an array/vector and binary search

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 1e6 + 2;
const int INF = 0x3f3f3f3f;

int n, p, arr[MM], bit[MM];
ll ans, psa[MM];
vector<ll> c;

void update(ll i, int val){
    for(; i<=MM; i+=i&-i){
        bit[i] += val;
    }
}

ll pre(ll i){
    ll ret = 0;
    for(; i>0; i-=i&-i){
        ret += bit[i];
    }
    return ret;
}

ll sum(int l, int r){
    return pre(r) - pre(l-1);
}

void solve() {
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    cin >> p;
    for(int i = 1; i<=n; i++){
        arr[i] -= p;
        psa[i] = psa[i-1] + arr[i];
        c.push_back(psa[i]);
    }
    sort(all(c));
    c.resize(unique(all(c))-c.begin());
    ll idx = lower_bound(c.begin(), c.end(), 0) - c.begin() + 1;
    update(idx, 1);
    for(int i = 1; i<=n; i++){
        ll v = lower_bound(c.begin(), c.end(), psa[i]) - c.begin() + 1;
        ans += pre(v);
        update(v, 1);
    }
    cout << ans << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while(TC--) solve();
}