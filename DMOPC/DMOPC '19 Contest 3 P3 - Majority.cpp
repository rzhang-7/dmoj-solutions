#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc19c3p3

void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 15002;

int n, psa, bit[2*MM];
ll ans;

void update(int i, int val) {
    for (i+=MM; i <= 2*MM; i += i & -i) {
        bit[i] += val;
    }
}

ll pre(int i) {
    ll ret = 0;
    for (i+=MM; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

void solve() {
    cin >> n;
    update(0, 1);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        psa += ((x & 1) ? 1 : -1);
        ans += pre(psa-1);
        update(psa, 1);
    }
    cout << ans << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}