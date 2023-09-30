#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc22s4

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 1e6 + 2;

int n, c, arr[2*MM], cnt[MM];
ll ans;

ll nC2(int num){
    if(num < 2) return 0;
    return (ll)num*(num-1)/2;
}

void solve() {
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i+n] = arr[i] + c;
        cnt[arr[i]]++;
    }
    sort(arr, arr+2*n);
    // get total combinations
    ans = (ll)n*(n-1)*(n-2)/6;

    // subtract invalid combinations
    for(int i = 0, j = 0; i<n; i++){
        while(j < 2*n && arr[j]-arr[i]<=c/2) j++;
        ans -= nC2(j-i-1);
    }

    // add back duplicates
    if(!(c&1)){
        for(int i = 0; i<c/2; i++){
            ans += cnt[i] * nC2(cnt[i+c/2]) + cnt[i+c/2] * nC2(cnt[i]);
        }
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