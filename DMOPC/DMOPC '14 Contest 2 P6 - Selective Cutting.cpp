#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/dmopc14c2p6

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 1e5 + 2;

pi arr[MM];
int n, q, bit[MM], ans[MM];

struct qry{
    int l, r, k, id;
} qs[MM];

bool cmp(qry x, qry y){
    return x.k < y.k;
}

void update(int i, int val){
    for(; i<=MM; i+=i&-i){
        bit[i] += val;
    }
}

int pre(int i){
    int ret = 0;
    for(; i>0; i-=i&-i){
        ret += bit[i];
    }
    return ret;
}

int sum(int l, int r){
    return pre(r) - pre(l-1);
}

void solve() {
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
        update(i, arr[i].first);
    }
    cin >> q;
    for(int i = 1; i<=q; i++){
        cin >> qs[i].l >> qs[i].r >> qs[i].k; qs[i].id = i;
        qs[i].l++; qs[i].r++;
    }
    sort(arr+1, arr+n+1);
    sort(qs+1, qs+q+1, cmp);

    // do offline processing, set each value strictly lower than k to 0
    for(int i = 1, j = 1; i<=q; i++){
        while(j <= n && arr[j].first < qs[i].k){
            update(arr[j].second, -arr[j].first);
            j++;
        }
        ans[qs[i].id] = sum(qs[i].l, qs[i].r);
    }
    for(int i = 1; i<=q; i++){
        cout << ans[i] << "\n";
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while(TC--) solve();
}