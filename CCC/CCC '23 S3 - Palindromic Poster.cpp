#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc23s3

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K> using uset = unordered_set<K>;
typedef long long ll;
typedef pair<int, int> pi;

const int MM = 2e3 + 2;
const int INF = 0x3f3f3f3f;

int n, m, r, c, cntR, cntC;
char arr[MM][MM];

int checkR(int i){
    for(int lft = 1, rit = m; lft <= rit; lft++, rit--){
        if(arr[i][lft] != arr[i][rit]) return 0;
    }
    return 1;
}

int checkC(int i){
    for(int lft = 1, rit = n; lft <= rit; lft++, rit--){
        if(arr[lft][i] != arr[rit][i]) return 0;
    }
    return 1;
}

void solve() {
    cin >> n >> m >> r >> c;
    fill(&arr[0][0], &arr[0][0] + sizeof(arr), 'a');
    for(int i = r+1; i<=n; i++){
        arr[i][m] = arr[i][1] + 1;
    }
    for(int i = c+1; i<=m; i++){
        arr[n][i] = arr[1][i] + 1;
    }
    if(r != n && c == 0) arr[n][m] = 'c';
    if(r == n && c != 0){
        if(!(m&1) && c&1){
            cout << "IMPOSSIBLE\n";
            return;
        }
        for(int i = 1; i<=m; i++){
            arr[n][i] = arr[1][i] + !(i <= c/2 || i > m - c/2);
        }
        if(c&1){
            arr[n][(m+1)/2] = arr[1][(m+1)/2];
        }
    }
    if(r != 0 && c == m){
        if(!(n&1) && r&1){
            cout << "IMPOSSIBLE\n";
            return;
        }
        for(int i = 1; i<=n; i++){
            arr[i][m] = arr[i][1] + !(i <= r/2 || i > n - r/2);
        }
        if(r&1){
            arr[(n+1)/2][m] = arr[(n+1)/2][1];
        }
    }
    for(int i = 1; i<=n; i++)
        cntR += checkR(i);
    for(int i = 1; i<=m; i++)
        cntC += checkC(i);
    if(cntR != r || cntC != c){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i = 1; i<=n; i++, cout<<"\n"){
        for(int j = 1; j<=m; j++){
            cout << arr[i][j];
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