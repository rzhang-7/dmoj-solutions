#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/dpq

// 2D version of Longest Increasing Subsequence (LIS) problem
// Given an array A with (hi, vi), find the max sum of vi of a subsequence so that all hi in the subsequence are increasing
// To find all flowers j where h[j] < h[i] and getting the max dp value, use a max BIT
// The BIT index is the height, the value is dp

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 2e5 + 2;
const int INF = 0x3f3f3f3f;

int n, h[MM], b[MM];
ll ans, dp[MM], bit[MM];

void update(int i, ll val){
    for(; i<=MM; i+=i&-i){
        bit[i] = max(bit[i], val);
    }
}

ll pre(int i){
    ll ret = 0;
    for(; i>0; i-=i&-i){
        ret = max(ret, bit[i]);
    }
    return ret;
}

ll sum(int l, int r){
    return pre(r) - pre(l-1);
}

void solve() {
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> h[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> b[i];
    }
    for(int i = 1; i<=n; i++){
        dp[i] = pre(h[i]-1) + b[i];
        update(h[i], dp[i]);
        ans = max(ans, dp[i]);
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