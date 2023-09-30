#include <iostream>
#include <string.h>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/ccc13s4

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 1e5 + 2;
const int INF = 0x3f3f3f3f;

int n, m;
bool vis[MM];
vector<int> adj[MM], rev[MM];

void dfs(int cur, vector<int> g[]) {
    vis[cur] = true;
    for (int nbr : g[cur]) {
        if (!vis[nbr]) {
            dfs(nbr, g);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    int p, q;
    cin >> p >> q;
    dfs(p, adj);
    if (vis[q])
        cout << "yes\n";
    else {
        memset(vis, 0, sizeof(vis));
        dfs(p, rev);
        if (vis[q])
            cout << "no\n";
        else
            cout << "unknown\n";
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}