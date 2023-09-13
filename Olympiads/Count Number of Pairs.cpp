#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/oly18decp4

const int MM = 1e5;

int n, m, arr[MM];
ll ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	for(int i = 0; i<n-1; i++){
		int idx = (upper_bound(arr, arr+n, m-arr[i]) - arr);
		if(idx > i)
			ans += idx - i - 1;
	}
	cout<<ans<<"\n";
}