#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/raytracing

// store the heights as a freqency table in a 2d BIT (bit[i][h])

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = (1<<13) + 2;
const int INF = 0x3f3f3f3f;

int n, q, arr[MM], bit[MM][MM];

void update(int r, int c, int val){
    for(int i = r+1; i <= MM; i+=i&-i){
        for(int j = c+1; j <= MM; j+=j&-j){
            bit[i][j] += val;
        }
    }
}

int pre(int r, int c){
    int ans = 0;
    for(int i = r+1; i > 0; i-=i&-i){
        for(int j = c+1; j > 0; j-=j&-j){
            ans += bit[i][j];
        }
    }
    return ans;
}

int sum(int r1, int c1, int r2, int c2){
    return pre(r2, c2) - pre(r1-1, c2) - pre(r2, c1-1) + pre(r1-1, c1-1);
}

void solve() {
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        update(i, arr[i], 1);
    }
    cin >> q;
    for(int op, l, r, a, b; q--;){
        cin >> op >> l >> r;
        if(op == 1){
            cin >> a >> b;
            cout << sum(l, a, r, b) << "\n";
        } else {
            update(l, arr[l], -1);
            arr[l] = r;
            update(l, arr[l], 1);
        }
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}