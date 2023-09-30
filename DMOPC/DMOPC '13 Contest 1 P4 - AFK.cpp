#include <iostream>
#include <queue>
#include <string.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// https://dmoj.ca/problem/dmopc13c1p4

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 52;
const int INF = 0x3f3f3f3f;

int r, c, dist[MM][MM], dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
bool arr[MM][MM], vis[MM][MM];

void solve() {
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    cin >> c >> r;
    pi st, ed;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char x;
            cin >> x;
            arr[i][j] = (x == 'X');
            if (x == 'C') st = {i, j};
            if (x == 'W') ed = {i, j};
        }
    }
    vis[st.first][st.second] = 1;
    queue<pi> q;
    q.push(st);
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if (ni <= r && ni > 0 && nj <= c && nj > 0 && !arr[ni][nj] && !vis[ni][nj]) {
                vis[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }
    dist[ed.first][ed.second] < 60 && dist[ed.first][ed.second] ? cout << dist[ed.first][ed.second] << "\n" : cout << "#notworth\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    cin >> TC;
    while (TC--) solve();
}