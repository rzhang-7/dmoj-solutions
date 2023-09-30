#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

// https://dmoj.ca/problem/oly18novp7

const int MM = 1e5 + 1;
const int INF = 1e9;

ll x, y, ans, dist[MM];
bool vis[MM];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    queue<ll> q; q.push(x); vis[x] = 1;
    while (!q.empty()){
        ll cur = q.front(); q.pop();
        if(cur == y){
            cout << dist[y] << "\n";
            // for(int i = y; i!=x; i=pre[i]) cout<<i<<" ";
            return 0;
        }
        int a = 2*cur, b = cur+1, c = cur-1;
        if(a>=0 && a<MM && !vis[a]) {
            q.push(a);
            vis[a] = 1;
            dist[a] = dist[cur]+1;
            // pre[a] = cur;
        }
        if(b>=0 && b<MM && !vis[b]) {
            q.push(b);
            vis[b] = 1;
            dist[b] = dist[cur]+1;
            // pre[b] = cur;
        }
        if(c>=0 && c<MM && !vis[c]) {
            q.push(c);
            vis[c] = 1;
            dist[c] = dist[cur]+1;
            // pre[c] = cur;
        }
        //for (int i : {a, b, c}) {
        //     if (!vis[i] && i >= 0 && i <= 100000) {
        //         dist[i] = dist[cur] + 1;
        //         vis[i] = true;
        //         q.push(i);
        //     }
        // }
    }
}