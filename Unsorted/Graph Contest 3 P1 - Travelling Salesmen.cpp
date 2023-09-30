#include <iostream>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/graph3p1

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 3e4 + 2;
const int INF = 0x3f3f3f3f;

int n, m, k, ans, dist[MM];
bool vis[MM];
vector<int> adj[MM];
queue<int> q;

void solve() {
    cin >> n >> m;
    for(int i = 1, a, b; i<=m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> k;
    for(int i = 1, x; i<=k; i++){
        cin >> x;
        q.push(x);
        vis[x] = true;
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nbr : adj[cur]){
            if(!vis[nbr]){
                vis[nbr] = true;
                dist[nbr] = dist[cur] + 1;
                q.push(nbr);
                ans = max(ans, dist[nbr]);
            }
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