#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ioi01p1

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = (1<<10) + 1;

int n, bit[MM][MM];

void update(int r, int c, int val){
    for(int i = r; i <= n; i+=i&-i){
        for(int j = c; j <= n; j+=j&-j){
            bit[i][j] += val;
        }
    }
}

int qry(int r, int c){
    int ans = 0;
    for(int i = r; i > 0; i-=i&-i){
        for(int j = c; j > 0; j-=j&-j){
            ans += bit[i][j];
        }
    }
    return ans;
}

int sum(int r1, int c1, int r2, int c2){
    return qry(r2, c2) - qry(r1-1, c2) - qry(r2, c1-1) + qry(r1-1, c1-1);
}

void solve() {
    int tmp, op; cin >> tmp >> n;
    for(cin >> op; op != 3; cin >> op){
        if(op == 1){
            int x, y, a;
            cin >> x >> y >> a;
            x++; y++;
            update(x, y, a);
        }
        else if (op == 2){
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            l++; b++; r++; t++;
            cout << sum(l, b, r, t) << "\n";
        }
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while(TC--) solve();
}