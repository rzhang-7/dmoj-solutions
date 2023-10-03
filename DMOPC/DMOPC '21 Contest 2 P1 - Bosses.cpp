#include <iostream>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/dmopc21c2p1

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 1e6 + 2;
const int INF = 0x3f3f3f3f;

ll n, h, p, sum, arr[MM];

void solve() {
    cin >> n >> h >> p;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr+1, arr+n+1);
    ll ans = sum * p;
    for(int i = 1; i<=n; i++){
        sum -= arr[i];
        ans = min(ans, arr[i]*h + p * (sum - (n-i) * arr[i]));
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