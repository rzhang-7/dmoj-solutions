#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/ccc23s4

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
typedef pair<ll, ll> pll;

const int MM = 1e6 + 3;
const int INF = 0x3f3f3f3f;

struct Edge {
    int c, u, v, w, id;
    Edge(int cost, int uu, int vv, int weight, int i) {
        c = cost, u = uu, v = vv, w = weight, id = i;
    }
};

int n, m;
ll sum, dist[MM];
bool vis[MM];
vector<Edge> e;
vector<pair<pll, ll>> adj[MM];

bool cmp(Edge x, Edge y) { return x.c > y.c; }

void dijkstra(int a) {
    priority_queue<pll> pq;
    memset(dist, INF, sizeof(dist));
    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
        pll cur = pq.top();
        pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for (auto x : adj[cur.second]) {
            if (!vis[x.second] && dist[x.first.first] > dist[cur.second] + x.first.second) {
                dist[x.first.first] = dist[cur.second] + x.first.second;
                pq.push({-dist[x.first.first], x.first.first});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0, u, v, l, c; i < m; i++) {
        cin >> u >> v >> l >> c;
        sum += c;
        adj[u].push_back({{v,l}, i});
        adj[v].push_back({{u,l}, i});
        e.push_back(Edge(c, u, v, l, i));
    }
    sort(e.begin(), e.end(), cmp);
    for (Edge x : e) {
        vis[x.id] = 1;
        // dbg(sum);
        dijkstra(x.u);
        if (dist[x.v] <= (ll)x.w)
            sum -= x.c;
        else
            vis[x.id] = 0;
    }
    cout << sum << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}