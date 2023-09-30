#include <iostream>
using namespace std;

// https://dmoj.ca/problem/checkerhard

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define int long long

typedef long long ll;
typedef pair<int, int> pi;

const int MM = 3002;

// technically only need one BIT, update x if r+c is even, otherwise update -x
// also for each query operation output as negative if r1+c1 is odd, otherwise positive
// i.e., cout<<((r1+c1)&1 ? -sum(r1,c1,r2,c2) : sum(r1,c1,r2,c2))

int M, N, arr[MM][MM], even[MM][MM], odd[MM][MM];

void update(int bit[][MM], int r, int c, int val){
    for(int i = r; i <= M; i+=i&-i){
        for(int j = c; j <= N; j+=j&-j){
            bit[i][j] += val;
        }
    }
}

int pre(int bit[][MM], int r, int c){
    int ans = 0;
    for(int i = r; i > 0; i-=i&-i){
        for(int j = c; j > 0; j-=j&-j){
            ans += bit[i][j];
        }
    }
    return ans;
}

int sum(int bit[][MM], int r1, int c1, int r2, int c2){
    return pre(bit, r2, c2) - pre(bit, r1-1, c2) - pre(bit, r2, c1-1) + pre(bit, r1-1, c1-1);
}

void solve() {
    cin >> M >> N;
    int op;
    for(cin>>op; op; cin>>op){
        int r1, c1, r2, c2, x;
        if(op == 1){
            cin >> r1 >> c1 >> x;
            update(((r1 + c1) & 1 ? odd : even), r1, c1, x-arr[r1][c1]);
            arr[r1][c1] = x;
        }
        else if (op == 2){
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sum(((r1 + c1) & 1 ? odd : even), r1, c1, r2, c2) - sum(((r1 + c1) & 1 ? even : odd), r1, c1, r2, c2) << "\n";
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