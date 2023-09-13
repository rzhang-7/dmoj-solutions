#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc5jp2

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, o, ans = 0;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>m>>o;
        if(m>o) ans++;
    }
    cout<<ans<<"\n";
}